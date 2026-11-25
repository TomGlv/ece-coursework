cmake_minimum_required(VERSION 3.26)
project(exo_cours_tableau C)

set(CMAKE_C_STANDARD 23)

add_executable(exo_cours_tableau main.c
        saisirTableau.c
        saisirTableau.h)
