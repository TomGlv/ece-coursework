cmake_minimum_required(VERSION 3.26)
project(exo_liste_personnnes C)

set(CMAKE_C_STANDARD 23)

add_executable(exo_liste_personnnes main.c
        header.c
        header.h)
