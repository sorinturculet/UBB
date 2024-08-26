cmake_minimum_required(VERSION 3.27)
project(c C)

set(CMAKE_C_STANDARD 11)

add_executable(c main.c
        domain/tranzactie.c
        domain/tranzactie.h
        list/list.c
        list/list.h
        service/service.c
        service/service.h
        ui/ui.c
        ui/ui.h)
