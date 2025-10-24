#pragma once

#include <initializer_list>

template<typename T>
class Array {
private:
    // Указатель на динамический массив символов
    T* data_ptr = nullptr;

    // Размер массива
    std::size_t size = 0;
    std::size_t capacity = 0;
public:
    // Конструктор по умолчанию
    Array();
    // Конструктор с размером
    Array(std::size_t);
    // Конструктор с размером и значением по умолчанию
    Array(std::size_t, T);
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
    T& operator[](std::size_t);
    T operator[](std::size_t) const;

    // Метод резервирования памяти
    void Reserve(std::size_t);
    // Метод изменения размера
    void Resize(std::size_t);

    // Метод получения размера
    std::size_t GetSize() const;

    // Методы добавления
    void PushBack(T);
    // Метод удаления
    T PopBack();

    // Метод вставки по индексу
    void Insert(std::size_t, T);
    // Метод удаления по индексу
    void Remove(std::size_t);

    // Метод очистки массива
    void Clear();
};

#include "./Array.tpp"