#include "../include/Octagon.hpp"

Octagon::Octagon() : Figure() {}

Octagon::Octagon(
    Point v1, Point v2, Point v3, Point v4,
    Point v5, Point v6, Point v7, Point v8
) : Figure() {
    this->_points.resize(this->GetPointCount());
    
    this->_points[0] = v1;
    this->_points[1] = v2;
    this->_points[2] = v3;
    this->_points[3] = v4;
    this->_points[4] = v5;
    this->_points[5] = v6;
    this->_points[6] = v7;
    this->_points[7] = v8;
}

double Octagon::Area() const {
    return 2.0 * (1.0 + sqrt(2)) * std::pow(this->Length(), 2);
}


size_t Octagon::GetPointCount() const { return 8; }