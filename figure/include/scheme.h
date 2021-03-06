#pragma once

#include "figure.h"

class Scheme {
public:
    Scheme(int capacity);
    ~Scheme();

    void push_back_figure(Figure* fg);
    void remove_figure(int id);

    void print_all_figures();
    void zoom_figure(int id, int factor);
    Figure* is_inside_figure(int x, int y);
    void move(int id, int new_x, int new_y);
    int find_figure_index_by_id(int id);

private:
    int size;
    int cap;
    Figure** figures_;
};
