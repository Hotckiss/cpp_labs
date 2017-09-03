#ifndef LINQ_H_
#define LINQ_H_

#include <utility>
#include <vector>

template<typename T, typename Iter>
class range_enumerator;
template<typename T>
class drop_enumerator;
template<typename T>
class take_enumerator;
template<typename T, typename U, typename F>
class select_enumerator;
template<typename T, typename F>
class until_enumerator;
template<typename T, typename F>
class where_enumerator;

template<typename T>
class enumerator {
public:
	virtual const T& operator*() = 0;
	virtual enumerator<T>& operator++() = 0;
	virtual operator bool() = 0;

	auto drop(int count) {
		return drop_enumerator<T>(*this, count);
	}

	auto take(int count) {
		return take_enumerator<T>(*this, count);
	}

	template<typename U = T, typename F>
	auto select(F func) {
		return select_enumerator<U, T, F>(*this, func);
	}

	template<typename F>
	auto until(F func) {
		return until_enumerator<T, F>(*this, func);
	}

	auto until_eq(T value) {
		return until([value](T x) { return x == value; });
	}

	auto until_neq(T value) {
		return until([value](T x) { return x != value; });
	}

	template<typename F>
	auto where(F func) {
		return where_enumerator<T, F>(*this, func);
	}

	auto where_eq(T value) {
		return where([value](T x) { return x == value; });
	}

	auto where_neq(T value) {
		return where([value](T x) { return x != value; });
	}

	std::vector<T> to_vector() {
		std::vector<T> res;
		while ((bool)*this) {
			res.push_back(std::move(*(*this)));
			++(*this);
		}
		return std::move(res);
	}

	template<typename Iter>
	void copy_to(Iter it) {
		while ((bool)*this) {
			*it = std::move(*(*this));
			it++;
			++(*this);
		}
	}
};

template<typename T, typename Iter>
class range_enumerator : public enumerator<T> {
public:
	range_enumerator(Iter begin, Iter end) : begin_(begin), end_(end) {
	}
	const T& operator*() override {
		return *begin_;
	}
	enumerator<T>& operator++() override {
		++begin_;
		return *this;
	}
	operator bool() override {
		return begin_ != end_;
	}
private:
	Iter begin_, end_;
};

template<typename T>
auto from(T begin, T end) {
	return range_enumerator<typename std::iterator_traits<T>::value_type, T>(begin, end);
}

template<typename T>
class drop_enumerator : public enumerator<T> {
public:
	drop_enumerator(enumerator<T> &parent, int count) : parent_(parent) {
		for (int i = 0; i < count; i++)
			if ((bool)parent_)
				++parent_;
	}
	const T& operator*() override {
		return *parent_;
	}
	enumerator<T>& operator++() override {
		++parent_;
		return *this;
	}
	operator bool() override {
		return (bool)parent_;
	}
private:
	enumerator<T>& parent_;
};

template<typename T>
class take_enumerator : public enumerator<T> {
public:
	take_enumerator(enumerator<T> &parent, int count) : parent_(parent), count_(count) {
		if (count_)
			is = false;
		else
			is = true;
	}
	const T& operator*() override {
		return *parent_;
	}
	enumerator<T>& operator++() override {
		++parent_;
		count_--;
		if (!count_)
			is = true;
		return *this;
	}
	operator bool() override {
		return !is && (bool)parent_;
	}
private:
	enumerator<T>& parent_;
	int count_;
	bool is;
};

template<typename T, typename U, typename F>
class select_enumerator : public enumerator<T> {
public:
	select_enumerator(enumerator<U> &parent, F& func) : parent_(parent), is(false), func_(std::move(func)) {}
	const T& operator*() override {
		if (!is) {
			cur = func_(*parent_);
			is = true;
		}
		return cur;
	}
	enumerator<T>& operator++() override {
		++parent_;
		is = false;
		return *this;
	}
	operator bool() override {
		return (bool)(parent_);
	}
private:
	enumerator<U>& parent_;
	T cur;
	bool is;
	F func_;
};

template<typename T, typename F>
class until_enumerator : public enumerator<T> {
public:
	until_enumerator(enumerator<T> &parent, F &predicate) : parent_(parent), predicate_(std::move(predicate)), is(false) {
		if (!parent_ || predicate_(*parent))
			is = true;
	}

	const T& operator*() override {
		return *parent_;
	}

	enumerator<T>& operator++() override {
		++parent_;
		if (parent_ && predicate_(*parent_))
			is = true;
		return *this;
	}

	operator bool() override {
		return !is && (bool)(parent_);
	}

private:
	enumerator<T> &parent_;
	F predicate_;
	bool is;
};

template<typename T, typename F>
class where_enumerator : public enumerator<T> {
public:
	where_enumerator(enumerator<T> &parent, F &predicate) : parent_(parent), predicate_(std::move(predicate)) {
		while (parent_ && !predicate_(*parent_))
			++parent_;
	}

	const T& operator*() override {
		return *parent_;
	}

	enumerator<T>& operator++() override {
		while (++parent_ && !predicate_(*parent_));
		return *this;
	}

	operator bool() override {
		return (bool)parent_;
	}

private:
	enumerator<T> &parent_;
	F predicate_;
};
#endif