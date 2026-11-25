cmake_minimum_required(VERSION 3.26)
project(allegtest C)

set(CMAKE_C_STANDARD 23)

add_executable(allegtest main.c header.c header.h)

target_link_libraries(allegtest -lmingw32 -lalleg44)