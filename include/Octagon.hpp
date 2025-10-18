#pragma once

#include "./Figure.hpp"

class Octagon : public Figure {
public:
    Octagon();
    ~Octagon() = default;

    Octagon(
        Point, Point, Point, Point,
        Point, Point, Point, Point
    );

    double Area() const override final;
    size_t GetPointCount() const override final;
};
