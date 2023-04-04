//
// Created by psp515 on 04/04/2023.
//
#include "circle.h"
#include <cmath>

namespace Shapes {
    bool Circle::isIn(int x, int y) const {
        return pow(center.x_ - x, 2) + pow(center.y_ - y, 2) <= pow(radius, 2);
    }

    Circle::Circle(int xFrom, int yFrom, int radius) noexcept {
        this->center.x_ = xFrom;
        this->center.y_ = yFrom;
        this->radius = radius;
    }
}