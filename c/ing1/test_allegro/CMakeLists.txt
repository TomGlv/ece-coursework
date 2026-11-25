cmake_minimum_required(VERSION 3.26)
project(test_allegro C)

set(CMAKE_C_STANDARD 23)

add_executable(test_allegro main.c)

target_link_libraries(test_allegro -lmingw32 -lalleg44)