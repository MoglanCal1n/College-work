cmake_minimum_required(VERSION 3.27)
project(lab2OOP_incase C)

set(CMAKE_C_STANDARD 11)

add_executable(lab2OOP_incase main.c
        domain.c
        domain.h
        repo.c
        repo.h
        service.c
        service.h
        ui.c
        ui.h
        tests.c
        tests.h)
