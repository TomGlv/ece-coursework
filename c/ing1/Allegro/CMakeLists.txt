cmake_minimum_required(VERSION 3.26)
project(Allegro C)

set(CMAKE_C_STANDARD 23)

add_executable(Allegro main.c)

target_link_libraries(Allegro -lmingw32 -lalleg44)
