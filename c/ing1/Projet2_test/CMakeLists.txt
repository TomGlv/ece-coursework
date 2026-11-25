cmake_minimum_required(VERSION 3.26)
project(Projet2_test C)

set(CMAKE_C_STANDARD 23)

add_executable(Projet2_test main.c
        menu.c
        menu.h
        "elements decors.c"
        deplacement.c
        timer.c
)
