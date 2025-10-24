#pragma once

#include <initializer_list>
#include <stdexcept>
#include <string>

template<typename T>
class Array {
private:
    // Указатель на динамический массив символов
    T* data_ptr = nullptr;

    // Размер массива
    size_t size = 0;
    size_t capacity = 0;
public:
    // Конструктор по умолчанию
    Array();
    // Конструктор с размером
    Array(size_t);
    // Конструктор с размером и значением по умолчанию
    Array(size_t, T);
    // Конструктор из параметров инициализации
    Array(std::initializer_list<T>);

    // Конструктор копирования
    Array(const Array&);
    // Конструктор перемещения
    Array(Array&&) noexcept;

    // Деструктор
    ~Array();

    // Оператор копирования
    Array& operator=(const Array&);
    // Оператор перемещения
    Array& operator=(Array&&) noexcept;

    // Операторы индексирования
    T& operator[](size_t idx);
    T operator[](size_t idz) const;

    // Метод получения размера
    size_t GetSize() const;

    // Методы добавления
    void PushBack(T);
    // Метод удаления
    T PopBack();

    // Метод вставки по индексу
    void Insert(size_t pos, T val);
    // Метод удаления по индексу
    void Remove(size_t pos);

    // Метод очистки
    void Clear();
};
