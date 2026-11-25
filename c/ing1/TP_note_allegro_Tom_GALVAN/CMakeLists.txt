cmake_minimum_required(VERSION 3.26)
project(TP_note_allegro_Tom_GALVAN C)

set(CMAKE_C_STANDARD 23)

add_executable(TP_note_allegro_Tom_GALVAN main.c)

target_link_libraries(TP_note_allegro_Tom_GALVAN -lmingw32 -lalleg44)