#pragma once

#include <cstddef>
#include <vector>
#include <istream>
#include <cmath>

struct Point {
    double x, y;
};

class Figure {
protected:
    // Список координат фигуры
    std::vector<Point> _points;

public:
    // Конструктор по умолчанию
    Figure();
    // Конструктор копирования
    Figure(const Figure&);
    virtual ~Figure() = default;;

    // Оператор копирования
    Figure& operator=(const Figure&);
    // Оператор перемещения
    Figure& operator=(Figure&&) noexcept;

    // Оператор чтения фигуры из потока
    friend std::istream& operator>>(std::istream&, Figure&);
    // Оператор вывода фигуры в поток
    friend std::ostream& operator<<(std::ostream&, const Figure&);

    // Оператор сравнения двух фигур
    bool operator==(const Figure&) const;

    // Оператор ЯВНОГО преобразования к типу double (вычисление площади)
    explicit operator double() const;

    // Метод вычисления длины стороны фигуры
    double Length() const;
    // Метод вычисления площади фигуры
    virtual double Area() const = 0;
    // Метод вычисление геометрического центра фигуры
    Point GeometricCenter() const;
    // Метод для получения количества вершин фигуры
    virtual size_t GetPointCount() const;
};
