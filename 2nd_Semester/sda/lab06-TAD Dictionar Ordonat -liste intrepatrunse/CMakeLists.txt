cmake_minimum_required(VERSION 3.28)
project(lab06_TAD_Dictionar_Ordonat__liste_intrepatrunse)

set(CMAKE_CXX_STANDARD 14)

include_directories("Proiect C++")
include_directories(Teste)

add_executable(lab06_TAD_Dictionar_Ordonat__liste_intrepatrunse
        "Proiect C++/App.cpp"
        "Proiect C++/DO.cpp"
        "Proiect C++/DO.h"
        "Proiect C++/Iterator.cpp"
        "Proiect C++/Iterator.h"
        Teste/TestExtins.cpp
        Teste/TestExtins.h
        Teste/TestScurt.cpp
        Teste/TestScurt.h)
