//
// Created by psp515 on 04/04/2023.
//

#ifndef ZAD4SHAPEDRAWING_DLASTUDENTOW_RECTANGLE_H
#define ZAD4SHAPEDRAWING_DLASTUDENTOW_RECTANGLE_H

#include "shape.h"

namespace Shapes
{
class Rectangle : public Shape
{
public:
    Rectangle(int xFrom,int yFrom,int xTo, int yTo) noexcept;

    [[nodiscard]] bool isIn(int x, int y) const override;
    [[nodiscard]] int x() const{
        return lowerLeft.x_;
    }
    [[nodiscard]] int xTo() const{
        return upperRight.x_;
    }

    [[nodiscard]] int y() const{
        return lowerLeft.y_;
    }

    [[nodiscard]] int yTo() const{
        return upperRight.y_;
    }

private:
    static bool between(int x, int b1, int b2);

    Shapes::Point lowerLeft{};
    Shapes::Point upperRight{};
};
}


#endif //ZAD4SHAPEDRAWING_DLASTUDENTOW_RECTANGLE_H
