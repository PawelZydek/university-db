cmake_minimum_required (VERSION 3.10)
project (university-db)
set (CMAKE_CXX_STANDARD 20)

set (SRC 
    src/Gender.cpp 
    src/Pesel.cpp
    src/Person.cpp
    src/Student.cpp)

set (FLAGS -Wall -Wextra -Wpedantic -Wno-conversion -Werror)

# MAIN EXECUTABLE
add_executable (${PROJECT_NAME} src/main.cpp ${SRC})
target_compile_options (${PROJECT_NAME} PRIVATE ${FLAGS})

# TEST EXECUTABLES
add_executable (${PROJECT_NAME}-gender-ut tests/test-gender.cpp ${SRC} tests/catch_amalgamated.cpp)
target_include_directories(${PROJECT_NAME}-gender-ut PUBLIC
    src
)

add_executable (${PROJECT_NAME}-pesel-ut tests/test-pesel.cpp ${SRC} tests/catch_amalgamated.cpp)
target_include_directories(${PROJECT_NAME}-pesel-ut PUBLIC
    src
)

enable_testing ()
add_test (NAME gender-tests COMMAND ${PROJECT_NAME}-gender-ut)
