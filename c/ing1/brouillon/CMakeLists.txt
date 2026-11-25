cmake_minimum_required(VERSION 3.26)
project(brouillon C)

set(CMAKE_C_STANDARD 23)

add_executable(brouillon main.c
        menu.c
        menu.h
)
