#include "myvector.hpp"
#include "template.hpp"
#include "myarray.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <chrono>

int main() {
    std::cout << "=== mySwap ===\n";
    int a = 5, b = 10;
    mySwap(a, b); // Обмен целыми числами
    std::cout << "a=" << a << ", b=" << b << "\n";

    std::string s1 = "one", s2 = "two";
    mySwap(s1, s2); // Обмен строками
    std::cout << "s1=" << s1 << ", s2=" << s2 << "\n";

    std::cout << "=== container_to_string ===\n";
    std::vector<int> v = {1, 2, 3};
    std::list<std::string> l = {"A", "B", "C"};
    std::set<double> st = {2.71, 3.14};
    std::cout << container_to_string(v) << "\n";
    std::cout << container_to_string(l) << "\n";
    std::cout << container_to_string(st) << "\n";

    std::cout << "=== MyArray ===\n";
    MyArray<int, 3> arr;
    for (size_t i = 0; i < arr.size(); ++i)
        arr[i] = static_cast<int>(i * 2); // Заполнение массива значениями

    for (size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    std::cout << "=== Move Semantics (MyVector) ===\n";
    size_t N = 1000000;
    MyVector mv1(N);
    for (size_t i = 0; i < N; ++i)
        mv1[i] = static_cast<int>(i); // Заполнение большого массива

    auto t1 = std::chrono::high_resolution_clock::now();
    MyVector mv2 = mv1; // копирующий конструктор
    auto t2 = std::chrono::high_resolution_clock::now();

    auto t3 = std::chrono::high_resolution_clock::now();
    MyVector mv3 = std::move(mv1); // move-конструктор
    auto t4 = std::chrono::high_resolution_clock::now();

    std::cout << "Copy time: " << std::chrono::duration<double>(t2 - t1).count() << " s\n";
    std::cout << "Move time: " << std::chrono::duration<double>(t4 - t3).count() << " s\n";
    std::cout << "mv1.size() = " << mv1.size() << ", mv3.size() = " << mv3.size() << "\n";

    return 0;
}
