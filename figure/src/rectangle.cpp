#include <cstdio>
#include "../include/rectangle.h"

Rectangle::Rectangle(int id, int x, int y, int width, int height) : Figure::Figure(id, x, y), w(width), h(height) {}
void Rectangle::print() const {
    printf("Rectangle %i: x = %i y = %i width = %i height = %i\n", id, x, y, w, h);
}
bool Rectangle::is_inside(int x, int y) const {
    return (2 * x <= 2 * this->x + w && 2 * x >= 2 * this->x - w && 2 * y <= 2 * this->y + h && 2 * y >= 2 * this->y - h);
}
void Rectangle::zoom(int factor) {
    w *= factor;
    h *= factor;
}
