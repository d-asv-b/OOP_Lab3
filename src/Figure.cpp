#include "../include/Figure.hpp"

#include <cmath>

Figure::Figure() {
    this->_points = Array<Point>(this->GetPointCount(), Point{ 0, 0 }); 
}

Figure::Figure(const Figure& obj) {
    if (this != &obj) {
        this->_points = Array<Point>(obj._points);
    }
}

Figure& Figure::operator=(const Figure& obj) {
    if (this != &obj) {
        this->_points = Array<Point>(obj._points);
    }

    return *this;
}

Figure& Figure::operator=(Figure&& obj) noexcept {
    if (this != &obj) {
        this->_points = std::move(obj._points);
    }

    return *this;
}

std::istream& operator>>(std::istream& input, Figure& obj) {
    obj._points.Clear();

    for (std::size_t i = 0; i < obj.GetPointCount(); ++i) {
        double coord_x, coord_y;
        input >> coord_x >> coord_y;

        obj._points.PushBack(Point{ coord_x, coord_y });
    }

    return input;
}

std::ostream& operator<<(std::ostream& output, const Figure& obj) {
    for (std::size_t i = 0; i < obj.GetPointCount(); ++i) {
        output << obj._points[i].x << obj._points[i].y;
    }

    return output;
}

bool Figure::operator==(const Figure& obj) const {
    if (this == &obj) {
        return true;
    }

    if (typeid(*this) != typeid(obj)) {
        return false;
    }

    if (this->GetPointCount() != obj.GetPointCount()) {
        return false;
    }

    for (std::size_t i = 0; i < this->GetPointCount(); ++i) {
        if (this->_points[i].x != obj._points[i].x || this->_points[i].y != obj._points[i].y) {
            return false;
        }
    }

    return true;
}

Point Figure::GeometricCenter() const {
    double sum_x = 0, sum_y = 0;

    for (std::size_t i = 0; i < this->GetPointCount(); ++i) {
        sum_x += this->_points[i].x;
        sum_y += this->_points[i].y;
    }

    return Point{ sum_x / this->GetPointCount(), sum_y / this->GetPointCount() };
}

Figure::operator double() const {
    return this->Area();
}

double Figure::Length() const {
    Point p1 = this->_points[0], p2 = this->_points[1];

    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

std::size_t Figure::GetPointCount() const { return 0; }