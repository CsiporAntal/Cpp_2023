//
// Created by Toni on 2023. 10. 18..
//

#include <valarray>
#include "Point.h"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point& point) const {
    int dx = point.x - x;
    int dy = point.y - y;
    return sqrt(dx * dx + dy * dy);
}