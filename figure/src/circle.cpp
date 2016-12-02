#include <cstring>
#include <cstdio>
#include "../include/circle.h"

Circle::Circle(int id, int x, int y, int radius, const char* label) : Figure(id, x, y), r(radius) {
    l = new char[strlen(label) + 1];
    strcpy(l, label);
}
Circle::~Circle() {
    delete[] l;
}
void Circle::print() const {
    printf("Circle %i: x = %i y = %i radius = %i label = %s\n", id, x, y, r, l);
}
bool Circle::is_inside(int x, int y) const {
    return ((x - this->x) * (x - this->x) + (y - this->y) * (y - this->y) <= r * r);
}
void Circle::zoom(int factor) {
    r *= factor;
}
