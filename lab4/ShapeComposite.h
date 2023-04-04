//
// Created by psp515 on 04/04/2023.
//

#ifndef ZAD4SHAPEDRAWING_DLASTUDENTOW_SHAPECOMPOSITE_H
#define ZAD4SHAPEDRAWING_DLASTUDENTOW_SHAPECOMPOSITE_H

#include "shape.h"

namespace Shapes {
    enum class ShapeOperation {
        INTERSECTION,
        SUM,
        DIFFERENCE
    };

    class ShapeComposite : public Shape {
    public:
        ShapeComposite(std::shared_ptr<Shape> shape1,
                       std::shared_ptr<Shape> shape2,
                       ShapeOperation operation);

        [[nodiscard]] bool isIn(int x, int y) const override;

    private:
        std::shared_ptr<Shapes::Shape> shape1;
        std::shared_ptr<Shapes::Shape> shape2;
        ShapeOperation operation;
    };
}

#endif //ZAD4SHAPEDRAWING_DLASTUDENTOW_SHAPECOMPOSITE_H
