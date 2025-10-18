#include "./include/Octagon.hpp"
#include "./include/Square.hpp"
#include "./include/Triangle.hpp"

#include <cstddef>
#include <iostream>

int main() {
    Octagon oct;
    Square square;
    Triangle triang;

    std::cout << "Введите координаты треугольника (3 штуки):\n";
    std::cin >> triang;

    std::cout << "\nВведите координаты квадрата (4 штуки):\n";
    std::cin >> square;

    std::cout << "\nВведите координаты восьмиугольника (8 штук):\n";
    std::cin >> oct;
    std::cout << "\n";

    std::vector<Figure*> figures{&triang, &square, &oct};

    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Сравниваем объекты типов " << typeid(*figures[i]).name() 
                  << " и " << typeid(*figures[(i + 1) % figures.size()]).name() << ": ";
        std::cout << ((*figures[i] == *figures[(i + 1) % figures.size()]) ? "Равны" : "НЕ равны") << "\n";

        Point p = figures[i]->GeometricCenter();
        std::cout << "Площадь фигуры " << typeid(*figures[i]).name() << " равна " 
                  << figures[i]->Area() << ", координаты её геометрического центра - X: " << p.x << " Y: " << p.y << "\n\n";
    }

    return 0;
}