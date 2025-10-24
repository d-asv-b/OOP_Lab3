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
        std::cout << "Сравниваем объекты типов " << figures[i]->GetTypeName()
                  << " и " << figures[(i + 1) % figures.GetSize()]->GetTypeName() << ": они ";
        std::cout << ((*figures[i] == *figures[(i + 1) % figures.GetSize()]) ? "Равны" : "НЕ равны") << "\n";

        Point p = figures[i]->GeometricCenter();
        std::cout << "Площадь фигуры " << figures[i]->GetTypeName() << " равна " 
                  << figures[i]->Area() << ", координаты её геометрического центра - X: " << p.x << " Y: " << p.y << "\n\n";

        total_area += figures[i]->Area();
    }

    // Выводим общую площадь всех трёх фигур.
    std::cout << "Общая площадь фигур в массиве: " << total_area << "\n";

    std::cout << "\n-------------------------------------------------------------------\n";
    // Проверим функции удаления и добавления в массив по индексу.

    std::cout << "\nСейчас набор фигур в массиве такой:\n";
    for (size_t i = 0; i < figures.GetSize(); ++i) {
        std::cout << i + 1 << ") " << figures[i]->GetTypeName() << " ";
    }
    

    // Удаляем вторую фигуру
    std::cout << "\n\nУдаляем фигуру номер 2 (индекс 1)\n";
    Figure* tmp = figures[1];
    figures.Remove(1);

    std::cout << "\nТеперь набор фигур в массиве выглядит так:\n";
    for (size_t i = 0; i < figures.GetSize(); ++i) {
        std::cout << i + 1 << ") " << figures[i]->GetTypeName()  << " ";
    }

    // Добавляем удаленную фигуру в начало массива
    std::cout << "\n\nДобавляем удаленную фигуру в самое начало массива (индекс 0)\n";
    figures.Insert(0, tmp);

    std::cout << "Теперь набор фигур в массиве такой:\n";
    for (size_t i = 0; i < figures.GetSize(); ++i) {
        std::cout << i + 1 << ") " << figures[i]->GetTypeName() << " ";
    }

    std::cout << "\n\n";

    return 0;
}