cmake_minimum_required(VERSION 3.28)
project(lab08_TAD_Arbore_binar__inlanturi_pe_tablou)

set(CMAKE_CXX_STANDARD 14)

include_directories("Proiect C++")
include_directories(Teste)

add_executable(lab08_TAD_Arbore_binar__inlanturi_pe_tablou
        "Proiect C++/AB.cpp"
        "Proiect C++/AB.h"
        "Proiect C++/App.cpp"
        "Proiect C++/IteratorAB.cpp"
        "Proiect C++/IteratorAB.h"
        Teste/TestExtins.cpp
        Teste/TestExtins.h
        Teste/TestScurt.cpp
        Teste/TestScurt.h)
