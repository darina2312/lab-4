cmake_minimum_required(VERSION 3.10)
project(lab-4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(Lab4 main.cpp
        myvector.cpp
        template.hpp
        myarray.hpp
        myvector.hpp
)
