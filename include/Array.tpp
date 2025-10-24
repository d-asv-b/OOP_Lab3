#include <stdexcept>
#include <utility>
#include <algorithm> 

template<typename T> Array<T>::Array() { }

template<typename T> Array<T>::Array(std::size_t size) {
    if (size > 0) {
        this->data_ptr = new T[size]();
        this->size = this->capacity = size;
    }
}

template<typename T> Array<T>::Array(std::size_t size, T default_val) {
    if (size > 0) {
        this->data_ptr = new T[size];
        for (std::size_t i = 0; i < size; ++i) {
            this->data_ptr[i] = default_val;
        }

        this->size = this->capacity = size;
    }
}

template<typename T> Array<T>::Array(std::initializer_list<T> params) {
    if (params.size() > 0) {
        this->data_ptr = new T[params.size()]();

        std::size_t i = 0;
        for (auto elem : params) {
            this->data_ptr[i] = elem;
            ++i;
        }

        this->size = this->capacity = params.size();
    }
}

template<typename T> Array<T>::Array(const Array& other) {
    if (this != &other) {
        this->size = other.size;
        this->capacity = other.capacity;

        this->data_ptr = new T[this->capacity];
        
        for (std::size_t i = 0; i < this->size; ++i) {
            this->data_ptr[i] = other.data_ptr[i];
        }
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

template<typename T> T& Array<T>::operator[](std::size_t idx) {
    if (idx > this->size) {
        throw std::out_of_range("Array index out of range");
    }

    return this->data_ptr[idx];
}

template<typename T> T Array<T>::operator[](std::size_t idx) const {
    if (idx > this->size) {
        throw std::out_of_range("Array index out of range");
    }

    return this->data_ptr[idx];
}

template<typename T> void Array<T>::Reserve(std::size_t new_capacity) {
    if (new_capacity <= this->capacity) {
        return;
    }

    this->capacity = new_capacity;
    T* new_mem = new T[this->capacity]();

    for (std::size_t i = 0; i < this->size; ++i) {
        new_mem[i] = std::move(this->data_ptr[i]);
    }

    delete[] this->data_ptr;
    this->data_ptr = new_mem;    
}

template<typename T> void Array<T>::Resize(std::size_t new_size) {
    if (new_size < this->size) {
        for (std::size_t i = new_size; i < this->size; ++i) {
            this->data_ptr[i] = T{};
        }
    }

    if (new_size > this->capacity) {
        this->Reserve(std::max(new_size, this->capacity * 2));
    }

    if (new_size > this->size) {
        for (std::size_t i = this->size; i < new_size; ++i) {
            this->data_ptr[i] = T{};
        }
    }

    this->size = new_size;
}

template<typename T> Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] this->data_ptr;

        this->size = other.size;
        this->capacity = other.capacity;

        this->data_ptr = new T[this->capacity];
        
        for (std::size_t i = 0; i < this->size; ++i) {
            this->data_ptr[i] = other.data_ptr[i];
        }
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

template<typename T> std::size_t Array<T>::GetSize() const {
    return this->size;
}

template<typename T> void Array<T>::PushBack(T val) {
    this->Resize(this->size + 1);
    this->data_ptr[this->size - 1] = val;
}

template<typename T> T Array<T>::PopBack() {
    if (this->size == 0) {
        throw std::out_of_range("Array is empty");
    }

    --this->size;
    return this->data_ptr[this->size];
}

template<typename T> void Array<T>::Insert(std::size_t pos, T val) {
    if (pos > this->size) {
        throw std::out_of_range("Position is out of range");
    }

    this->Resize(this->size + 1);

    for (std::size_t i = this->size - 1; i > pos; --i) {
        this->data_ptr[i] = std::move(this->data_ptr[i - 1]);
    }

    this->data_ptr[pos] = val;
}

template<typename T> void Array<T>::Remove(std::size_t pos) {
    if (pos > this->size) {
        throw std::out_of_range("Position is out of range");
    }

    for (std::size_t i = pos; i < this->size - 1; ++i) {
        this->data_ptr[i] = std::move(this->data_ptr[i + 1]);;
    }

    this->Resize(this->size - 1);
}

template<typename T> void Array<T>::Clear() {
    for (std::size_t i = 0; i < this->size; ++i) {
        this->data_ptr[i] = T{};
    }

    this->size = 0;
}