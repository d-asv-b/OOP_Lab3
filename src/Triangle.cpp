#include "../include/Triangle.hpp"

#include <cmath>

Triangle::Triangle() : Figure() {}

Triangle::Triangle(Point v1, Point v2, Point v3) : Figure() {
    this->_points.Resize(this->GetPointCount());
    
    this->_points[0] = v1;
    this->_points[1] = v2;
    this->_points[2] = v3;
}

double Triangle::Area() const {
    return std::sqrt(3) * std::pow(this->Length(), 2) / 4.0;
}

size_t Triangle::GetPointCount() const { return 3; }

std::string Triangle::GetTypeName() const {
    return "Triangle";
}