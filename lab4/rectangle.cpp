//
// Created by psp515 on 04/04/2023.
//
#include "rectangle.h"

namespace Shapes {

    bool Rectangle::isIn(int x, int y) const{
        return between(x, lowerLeft.x_, upperRight.x_) &&
               between(y, lowerLeft.y_, upperRight.y_);
    }

    bool Rectangle::between(int x, int b1, int b2) {
        return b1 <= x && x <= b2;
    }

    Rectangle::Rectangle(int xFrom, int yFrom, int xTo, int yTo) noexcept {
        lowerLeft.x_ = xFrom;
        lowerLeft.y_ = yFrom;
        upperRight.x_ = xTo;
        upperRight.y_ = yTo;
    }
}