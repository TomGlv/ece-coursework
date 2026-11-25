cmake_minimum_required(VERSION 3.26)
project(Projet3_test C)

set(CMAKE_C_STANDARD 23)

add_executable(Projet3_test main.c
        menu.c
        menu.h
        deplacements_affichage.c
        bloc.c
        snoopy_struct.h
        sauvegarde.c
        graphisme.c
        initialisation.c)
