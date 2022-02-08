cmake_minimum_required(VERSION 3.20)
project(laba5b C)

set(CMAKE_C_STANDARD 11)

add_executable(laba5b main.c libs/data_structures/vector/vector.h libs/data_structures/vector/vector.c libs/data_structures/vector/vectorVoid.h libs/data_structures/vector/vectorVoid.c)
