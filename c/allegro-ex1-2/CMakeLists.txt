cmake_minimum_required(VERSION 3.30)
project(exo1_2_allegro C)

set(CMAKE_C_STANDARD 23)

add_executable(exo1_2_allegro main.c)

target_link_libraries(exo1_2_allegro -lmingw32 -lalleg44)
