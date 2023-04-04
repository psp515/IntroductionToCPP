//
// Created by psp515 on 04/04/2023.
//

#ifndef ZAD4SHAPEDRAWING_DLASTUDENTOW_CIRCLE_H
#define ZAD4SHAPEDRAWING_DLASTUDENTOW_CIRCLE_H

#include "shape.h"

namespace Shapes {
    class Circle : public Shape {

    public:
        Circle(int xFrom, int yFrom, int radius) noexcept;


        [[nodiscard]] bool isIn(int x, int y) const override;

        [[nodiscard]] int x() const{
            return center.x_;
        }

        [[nodiscard]] int getRadius() const{
            return radius;
        }

        [[nodiscard]] int y() const{
            return center.y_;
        }

    private:
        int radius;
        Shapes::Point center{};
    };
}

#endif //ZAD4SHAPEDRAWING_DLASTUDENTOW_CIRCLE_H
