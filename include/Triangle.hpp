#pragma once

#include "./Figure.hpp"

class Triangle : public Figure {
public:
    Triangle();
    ~Triangle() = default;

    Triangle(
        Point, Point, Point
    );

    double Area() const override final;
    size_t GetPointCount() const override final;
    std::string GetTypeName() const override final;
};