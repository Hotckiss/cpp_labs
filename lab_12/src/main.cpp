#include <vector>
#include <cstring>
#include <cstdio>
#include "../include/my_vector.h"

template <class TT>
std::ostream& operator<<(std::ostream& fout, const my_vector<TT>& v) {
    for (size_t i = 0; i < v.size(); i++)
        fout << v[i] << " ";
    return fout;
}

class Product {
public:
    Product();
    Product(const char* name, int quantity, double price);
    Product(const Product & p);
    Product & operator=(const Product & p);
    bool operator==(const Product & p) const;
    ~Product();
    friend std::ostream& operator<<(std::ostream& fout, const Product& v);
private:
    char *name_;
    int quantity_;
    double price_;
};

Product::Product() {
    name_ = new char[1];
    name_[0] = '\0';
    quantity_ = 0;
    price_ = 0;
}
Product::Product(const char* name, int quantity, double price) {
    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);
    quantity_ = quantity;
    price_ = price;
}

Product::~Product() {
    delete[] name_;
}

Product::Product(const Product & p) {
    name_ = new char[strlen(p.name_) + 1];
    strcpy(name_, p.name_);
    quantity_ = p.quantity_;
    price_ = p.price_;
}

Product & Product::operator=(const Product & p) {
    delete[] name_;
    name_ = new char[strlen(p.name_) + 1];
    strcpy(name_, p.name_);
    quantity_ = p.quantity_;
    price_ = p.price_;
    return *this;
}

bool Product::operator==(const Product & p) const {
    return (!strcmp(name_, p.name_)) && (quantity_ == p.quantity_) && (price_ == p.price_);
}

std::ostream& operator<<(std::ostream& fout, const Product& p) {
    fout << p.name_ << " " << p.quantity_ << " " << p.price_;
    return fout;
}

template<typename T>
void test_my_vector(const T arg1, const T arg2) {
    int failed = 0;
    my_vector<T> v1;
    my_vector<T> v2(2);
    for (size_t i = 0; i < 2000; i++)
        v1.push_back(arg1), v1.push_back(arg2);
    my_vector<T> v3(v1);
    my_vector<T> v4;
    v4 = v1;
    if (v4.size() != v3.size() || v4.size() != v1.size()) failed++;
    for (size_t i = 0; i < 2000; i++)
        if (!(v4[i] == v3[i]) || !(v4[i] == v1[i])) failed++;
    v1.resize(8192);
    if (!(v1.size() == 8192)) failed++;
    v1.resize(8193);
    if (!(v1.size() == 8193)) failed++;
    v1.resize(8191);
    if (!(v1.size() == 8191)) failed++;
    v2.reserve(10000);
    if (!(v1.capacity() == 16384)) failed++;
    v2.clear();
    if (!(v2.size() == 0)) failed++;
    v1.pop_back();
    if (!(v1.size() == 8190)) failed++;
    v1.push_back(arg2);
    if (!(v1.size() == 8191)) failed++;
    if (!(v1[v1.size() - 1] == arg2)) failed++;
    fprintf(stderr, "Failed %i tests\n", failed);
}
int main() {
    test_my_vector<int>(5, 10);
    test_my_vector<Product>(Product("asdf", 4, 12.0), Product("qwe", -1, 7.5));
    my_vector<int> v1;
    my_vector<Product> v2;
    v1.push_back(1);
    v2.push_back(Product("asdf", 4, 12.0));
    v1.push_back(2);
    v2.push_back(Product("qwe", -1, 7.5));
    std::cout << v1 << "\n" << v2 << "\n";
    return 0;
}
