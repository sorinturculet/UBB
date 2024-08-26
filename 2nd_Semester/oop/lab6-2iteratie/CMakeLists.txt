cmake_minimum_required(VERSION 3.27)
project(lab6)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab6 main.cpp
        UI.cpp
        UI.h
        Repository.cpp
        Repository.h
        Service.cpp
        Service.h
        Domain.cpp
        Domain.h
        validator.h
        vector.cpp
        vector.h)
