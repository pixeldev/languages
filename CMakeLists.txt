cmake_minimum_required(VERSION 3.29)
project(second_practice C)

set(CMAKE_C_STANDARD 23)

add_executable(second_practice main.c
        language.c
        language.h
        set.c
        set.h
        string.c
        string.h
)
