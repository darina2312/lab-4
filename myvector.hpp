#pragma once
#include <cstddef>

// Класс-обёртка над динамическим массивом с поддержкой move-семантики
class MyVector {
public:
    MyVector();                         // Конструктор по умолчанию
    explicit MyVector(size_t size);    // Конструктор с параметром размера
    ~MyVector();                        // Деструктор

    MyVector(const MyVector& other);               // Копирующий конструктор
    MyVector& operator=(const MyVector& other);    // Оператор копирующего присваивания

    MyVector(MyVector&& other) noexcept;           // Move-конструктор
    MyVector& operator=(MyVector&& other) noexcept;// Move-оператор присваивания

    size_t size() const { return m_size; }
    int& operator[](size_t index) { return m_data[index]; }
    const int& operator[](size_t index) const { return m_data[index]; }

private:
    size_t m_size;  // Кол-во элементов
    int* m_data;    // Указатель на динамически выделенный массив
};