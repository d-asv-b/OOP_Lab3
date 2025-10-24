#include "../include/Array.hpp"
#include <cstring>
#include <initializer_list>

template<typename T> Array<T>::Array() { }

template<typename T> Array<T>::Array(size_t size) {
    if (size > 0) {
        this->data_ptr = new unsigned char[size]();
        this->size = this->capacity = size;
    }
}

template<typename T> Array<T>::Array(size_t size, T default_val) {
    if (size > 0) {
        this->data_ptr = new unsigned char[size];
        std::memset(this->data_ptr, default_val, size);

        this->size = this->capacity = size;
    }
}

template<typename T> Array<T>::Array(std::initializer_list<T> params) {
    if (params.size() > 0) {
        this->data_ptr = new T[params.size()]();

        for (size_t i = 0; i < params.size(); ++i) {
            this->data_ptr[i] = params[i];
        }
    }
}

template<typename T> Array<T>::Array(const Array& other) {
    if (this != &other) {
        this->size = other.size;
        this->capacity = other.capacity;

        this->data_ptr = new T[this->capacity];
        std::memcpy(this->data_ptr, other.data_ptr, this->size);
    }
}

template<typename T> Array<T>::Array(Array&& other) noexcept {
    if (this != &other) {
        this->data_ptr = other.data_ptr;
        this->size = other.size;
        this->capacity = other.capacity;

        other.data_ptr = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
}

template<typename T> Array<T>::~Array() {
    delete[] this->data_ptr;
    this->data_ptr = nullptr;
    this->size = this->capacity = 0;
}

template<typename T> T& Array<T>::operator[](size_t idx) {
    if (idx >= size) {
        throw std::out_of_range("Array index out of range");
    }

    return this->data_ptr[idx];
}

template<typename T> T Array<T>::operator[](size_t idx) const {
    if (idx >= size) {
        throw std::out_of_range("Array index out of range");
    }

    return this->data_ptr[idx];
}

template<typename T> Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] this->data_ptr;

        this->size = other.size;
        this->capacity = other.capacity;

        this->data_ptr = new unsigned char[this->capacity];
        std::memcpy(this->data_ptr, other.data_ptr, this->size);
    }

    return *this;
}

template<typename T> Array<T>& Array<T>::operator=(Array<T>&& other) noexcept {
    if (this != &other) {
        delete[] this->data_ptr;

        this->data_ptr = other.data_ptr;
        this->size = other.size;
        this->capacity = other.capacity;

        other.data_ptr = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    return *this;
}

template<typename T> size_t Array<T>::GetSize() const {
    return this->size;
}

template<typename T> void Array<T>::PushBack(T val) {
    if (this->size + 1 > this->capacity) {
        this->capacity *= 2;
        
        T* new_mem = new T[this->capacity]();
        std::memcpy(new_mem, this->data_ptr, this->size);

        delete[] this->data_ptr;
        this->data_ptr = new_mem;
    }

    this->data_ptr[this->size] = val;
    ++this->size;
}

template<typename T> T Array<T>::PopBack() {
    --this->size;
    return this->data_ptr[size];
}

template<typename T> void Array<T>::Insert(size_t pos, T val) {
    if (this->size + 1 > this->capacity) {
        this->capacity *= 2;
        
        T* new_mem = new T[this->capacity]();
        std::memcpy(new_mem, this->data_ptr, this->size);

        delete[] this->data_ptr;
        this->data_ptr = new_mem;
    }

    memcpy(this->data_ptr + pos + 1, this->data_ptr + pos, this->size - pos);
    this->data_ptr[pos] = val;
    ++(this->size);
}

template<typename T> void Array<T>::Remove(size_t pos) {
    memcpy(this->data_ptr + pos, this->data_ptr + pos + 1, this->size - pos);
    --(this->size);
}

template<typename T> void Array<T>::Clear() {
    std::memset(this->data_ptr, 0, this->size);
    this->size = 0;
}