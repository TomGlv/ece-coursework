cmake_minimum_required(VERSION 3.26)
project(exos_chaines_dynamiques C)

set(CMAKE_C_STANDARD 23)

add_executable(exos_chaines_dynamiques main.c
        header.c
        header.h)
