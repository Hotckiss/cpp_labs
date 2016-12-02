#include <cstdio>
#include "../include/rectangle.h"

Rectangle::Rectangle(int id, int x, int y, int width, int height) : Figure::Figure(id, x, y), w(width), h(height) {}
void Rectangle::print() const {
    printf("Rectangle %i: x = %i y = %i width = %i height = %i\n", id, x, y, w, h);
}
bool Rectangle::is_inside(int x, int y) const {
    if(x <= this->x + w / 2 && x >= this->x - w / 2 && y <= this->y + h / 2 && y >= this->y - h / 2)
        return true;
    return false;
}
void Rectangle::zoom(int factor) {
    w *= factor;
    h *= factor;
}
