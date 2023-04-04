//
// Created by psp515 on 04/04/2023.
//

#include <memory>
#include "ShapeComposite.h"

namespace Shapes {
    bool ShapeComposite::isIn(int x, int y) const {
        switch (operation) {
            case ShapeOperation::INTERSECTION:
                return this->shape1->isIn(x, y) and this->shape2->isIn(x, y);
            case ShapeOperation::SUM:
                return this->shape1->isIn(x, y) or this->shape2->isIn(x, y);
            case ShapeOperation::DIFFERENCE:
                return this->shape1->isIn(x, y) and !this->shape2->isIn(x, y);
            default:
                return true;
        }
    }

    ShapeComposite::ShapeComposite(std::shared_ptr<Shape> shape1,
                                   std::shared_ptr<Shape> shape2,
                                   Shapes::ShapeOperation operation)
                                   : shape1(shape1),
                                   shape2(shape2),
                                   operation(operation) {}
}
