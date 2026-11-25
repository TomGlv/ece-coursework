cmake_minimum_required(VERSION 3.30)
project(musique_allegro C)

set(CMAKE_C_STANDARD 23)

add_executable(musique_allegro main.c)

target_link_libraries(musique_allegro -lmingw32 -lalleg44)