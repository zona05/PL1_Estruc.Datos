cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        NodoPila.cpp
        NodoPila.h
        Pila.cpp
        Pila.h
        Cola.cpp
        Cola.h
        NodoCola.cpp
        NodoCola.h)
