#pragma once

#include "./Figure.hpp"

class Square : public Figure {
public:
    Square();
    ~Square() = default;

    Square(
        Point, Point, Point, Point
    );

    double Area() const override final;
    size_t GetPointCount() const override final;
    std::string GetTypeName() const override final;
};