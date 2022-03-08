cmake_minimum_required(VERSION 3.20)
project(laba5b_5d C)

set(CMAKE_C_STANDARD 11)


add_executable(laba5b_5d main.c libs/data_structures/vector/vector.h
        libs/data_structures/vector/vector.c
        libs/data_structures/vector/vectorVoid.h
        libs/data_structures/vector/vectorVoid.c
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/matrix.h
        libs/algorithms/algorithms.h
        libs/algorithms/algorithms.c
        libs/string/string_.h
        libs/string/string_.c
        libs/string/tests/test_string.h
        libs/string/tests/test_string.c
        libs/string/tasks/removeNonLetters.h libs/string/tests/test_string_tasks.h libs/string/tasks/removeExtraSpaces.h libs/string/tasks/digitsToEndLettersToStart.h libs/string/tasks/replaceDigitForEquivalentCountOfSpaces.h)

add_subdirectory(libs)
target_link_libraries(laba5b_5d data_structures)
target_link_libraries(laba5b_5d algorithms)

