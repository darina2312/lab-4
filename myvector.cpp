#include "myvector.hpp"

MyVector::MyVector() : m_size(0), m_data(nullptr) {}

MyVector::MyVector(size_t size) : m_size(size), m_data(nullptr) {
    if (m_size > 0) {
        m_data = new int[m_size](); // Инициализация нулями
    }
}

MyVector::~MyVector() {
    delete[] m_data; // Освобождение памяти
}

// Копирующий конструктор — делает глубокую копию
MyVector::MyVector(const MyVector& other) : m_size(other.m_size), m_data(nullptr) {
    if (m_size > 0) {
        m_data = new int[m_size];
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }
}

// Оператор присваивания — сначала освобождает, потом копирует
MyVector& MyVector::operator=(const MyVector& other) {
    if (this == &other) return *this;

    delete[] m_data;
    m_size = other.m_size;
    m_data = nullptr;
    if (m_size > 0) {
        m_data = new int[m_size];
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}

// Move-конструктор — просто забираем ресурсы, не копируем
MyVector::MyVector(MyVector&& other) noexcept : m_size(other.m_size), m_data(other.m_data) {
    other.m_size = 0;
    other.m_data = nullptr;
}

// Move-оператор присваивания — освобождаем свои ресурсы и забираем чужие
MyVector& MyVector::operator=(MyVector&& other) noexcept {
    if (this == &other) return *this;

    delete[] m_data;
    m_size = other.m_size;
    m_data = other.m_data;

    other.m_size = 0;
    other.m_data = nullptr;

    return *this;
}