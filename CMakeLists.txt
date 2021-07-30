cmake_minimum_required (VERSION 3.10)
project (university-db)
set (CMAKE_CXX_STANDARD 17)

set (SRC Gender.cpp Pesel.cpp)
set (FLAGS -Wall -Wextra -Wpedantic -Wno-conversion -Werror)

# MAIN EXECUTABLE
add_executable (${PROJECT_NAME} main.cpp ${SRC})
target_compile_options (${PROJECT_NAME} PRIVATE ${FLAGS})

# TEST EXECUTABLES
add_executable (${PROJECT_NAME}-gender-ut test-gender.cpp ${SRC})

enable_testing ()
add_test (NAME gender-tests COMMAND ${PROJECT_NAME}-gender-ut)