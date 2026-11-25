cmake_minimum_required(VERSION 3.30)
project(allegro C)

set(CMAKE_C_STANDARD 23)

add_executable(allegro main.c)

target_link_libraries(allegro -lmingw32 -lalleg44)
