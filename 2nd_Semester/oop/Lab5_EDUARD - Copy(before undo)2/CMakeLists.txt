cmake_minimum_required(VERSION 3.27)
project(Lab5_EDUARD C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lab5_EDUARD
        list/listamea.c
        list/listamea.h
        service/Service.c
        service/Service.h
        Source.c
        Teste.c
        Teste.h
        domain/domain.c
        domain/domain.h)
