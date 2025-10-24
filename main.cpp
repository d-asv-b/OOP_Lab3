#include "./include/Octagon.hpp"
#include "./include/Square.hpp"
#include "./include/Triangle.hpp"
#include "./include/Array.hpp"

#include <cstddef>
#include <iostream>

int main() {
    // Инициализация объектов фигур
    Octagon oct;
    Square square;
    Triangle triang;

    // Вводим координаты фигур
    std::cout << "Введите координаты треугольника (3 штуки):\n";
    std::cin >> triang;

    std::cout << "\nВведите координаты квадрата (4 штуки):\n";
    std::cin >> square;

    std::cout << "\nВведите координаты восьмиугольника (8 штук):\n";
    std::cin >> oct;
    std::cout << "\n";

    // Заносим объекты фигур в массив (Array)
    Array<Figure*> figures{&triang, &square, &oct};

    double total_area = 0;

    // Сравниваем объекты между собой и вычисляем у каждой фигуры площадь и координаты геометрического центра
    for (size_t i = 0; i < figures.GetSize(); ++i) {
        std::cout << "Сравниваем объекты типов " << typeid(*figures[i]).name() 
                  << " и " << typeid(*figures[(i + 1) % figures.GetSize()]).name() << ": ";
        std::cout << ((*figures[i] == *figures[(i + 1) % figures.GetSize()]) ? "Равны" : "НЕ равны") << "\n";

        Point p = figures[i]->GeometricCenter();
        std::cout << "Площадь фигуры " << typeid(*figures[i]).name() << " равна " 
                  << figures[i]->Area() << ", координаты её геометрического центра - X: " << p.x << " Y: " << p.y << "\n\n";

        total_area += figures[i]->Area();
    }

    // Выводим общую площадь всех трёх фигур.
    std::cout << "\nОбщая площадь фигур в массиве: " << total_area << '\n';

    // Проверим функции удаления и добавления в массив по индексу.

    std::cout << "Сейчас набор фигур в массиве такой:\n";
    for (size_t i = 0; i < figures.GetSize(); ++i) {
        std::cout << i + 1 << ") " << typeid(*figures[i]).name() << ", ";
    }

    // Удаляем вторую фигуру
    Figure* tmp = figures[1];
    figures.Remove(1);

    std::cout << "Сейчас набор фигур в массиве такой:\n";
    for (size_t i = 0; i < figures.GetSize(); ++i) {
        std::cout << i + 1 << ") " << typeid(*figures[i]).name() << ", ";
    }

    // Добавляем удаленную фигуру в начало массива

    figures.Insert(0, tmp);

    std::cout << "Сейчас набор фигур в массиве такой:\n";
    for (size_t i = 0; i < figures.GetSize(); ++i) {
        std::cout << i + 1 << ") " << typeid(*figures[i]).name() << ", ";
    }

    return 0;
}