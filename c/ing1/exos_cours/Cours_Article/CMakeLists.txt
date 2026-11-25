cmake_minimum_required(VERSION 3.26)
project(Cours_Article C)

set(CMAKE_C_STANDARD 23)

add_executable(Cours_Article main.c
        Article.c
        Article.h)
