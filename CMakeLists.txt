cmake_minimum_required(VERSION 3.19)
project(internship_selection_lp1 C)

set(CMAKE_C_STANDARD 11)

include_directories(src/includes)

add_executable(internship_selection_lp1
        src/includes/domain.h
        src/main.c)
