#include "../include/Square.hpp"

#include <cmath>

Square::Square() : Figure() {}

Square::Square(Point v1, Point v2, Point v3, Point v4) : Figure()  {
    this->_points.Resize(this->GetPointCount());
    
    this->_points[0] = v1;
    this->_points[1] = v2;
    this->_points[2] = v3;
    this->_points[3] = v4;
}

double Square::Area() const {
    return std::pow(this->Length(), 2);
}

size_t Square::GetPointCount() const { return 4; }

std::string Square::GetTypeName() const {
    return "Square";
}