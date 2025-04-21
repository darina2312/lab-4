#pragma once
#include <sstream>
#include <string>
#include <utility>

// Шаблонная функция обмена значениями двух переменных через move-семантику
// Работает быстрее для типов, поддерживающих перемещение
template <typename T>
void mySwap(T& a, T& b) {
    T temp = std::move(a); // переместили a во временную переменную
    a = std::move(b);       // переместили b в a
    b = std::move(temp);    // переместили временную переменную в b
}

// Преобразует любой контейнер (vector, list, set...) в строку формата { 1, 2, 3 }
// Полезно для отладки и вывода
template <typename Container>
std::string container_to_string(const Container& cont) {
    std::ostringstream oss;
    oss << "{ ";
    for (auto it = cont.begin(); it != cont.end(); ++it) {
        oss << *it;
        if (std::next(it) != cont.end()) oss << ", ";
    }
    oss << " }";
    return oss.str();
}