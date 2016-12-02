#include <cstdio>
#include "../include/scheme.h"

Scheme::Scheme(int capacity) {
    this->size = 0;
    this->cap = capacity;
    this->figures_ = new Figure*[capacity];
}
Scheme::~Scheme() {
    for (int i = 0; i < this->size; i++)
        delete figures_[i];
    delete[] figures_;
}
void Scheme::push_back_figure(Figure* fg) {
    if (size == cap) return;
    this->figures_[size] = fg;
    (this->size)++;
}
int Scheme::find_figure_index_by_id(int id) {
    for (int i = 0; i < size; i++)
        if (figures_[i]->get_id() == id)
            return i;
    return -1;
}
void Scheme::remove_figure(int id) {
    int ind = find_figure_index_by_id(id);
    if (ind == -1) return;
    delete figures_[ind];
    for (int j = ind; j < size - 1; j++)
        figures_[j] = figures_[j + 1];
    size--;
}
void Scheme::print_all_figures() {
    for (int i = 0; i < size; i++)
        figures_[i]->print();
}
void Scheme::zoom_figure(int id, int factor) {
    int ind = find_figure_index_by_id(id);
    if (ind == -1) return;
    figures_[ind]->zoom(factor);
}
Figure* Scheme::is_inside_figure(int x, int y) {
    for (int i = 0; i < size; i++)
        if (figures_[i]->is_inside(x, y))
            return figures_[i];
    return NULL;
}
void Scheme::move(int id, int new_x, int new_y) {
    int ind = find_figure_index_by_id(id);
    if (ind == -1) return;
    figures_[ind]->move(new_x, new_y);
}
