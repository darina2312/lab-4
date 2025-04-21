#pragma once
#include <cstddef>

// Простой шаблонный массив фиксированной длины
// Аналог std::array
template <typename T, size_t N>
class MyArray {
public:
    MyArray() = default;
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }
    size_t size() const { return N; }

private:
    T data[N]; // Храним элементы прямо в объекте
};