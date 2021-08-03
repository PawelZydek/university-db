cmake_minimum_required (VERSION 3.10)
project (university-db)
set (CMAKE_CXX_STANDARD 20)

set (SRC 
    src/Gender.cpp 
    src/Pesel.cpp
    src/Person.cpp
    src/Student.cpp
    src/Employee.cpp
    src/UniversityBase.cpp)

set (FLAGS -Wall -Wextra -Wpedantic -Wno-conversion -Werror -g -O0)

# MAIN EXECUTABLE
add_executable (${PROJECT_NAME} src/main.cpp ${SRC})
target_compile_options (${PROJECT_NAME} PRIVATE ${FLAGS})

# TEST EXECUTABLES
add_executable (${PROJECT_NAME}-gender-ut tests/test-gender.cpp ${SRC} tests/catch_amalgamated.cpp)
target_include_directories(${PROJECT_NAME}-gender-ut PUBLIC
    src
)
target_compile_options (${PROJECT_NAME}-gender-ut PRIVATE ${FLAGS})

add_executable (${PROJECT_NAME}-pesel-ut tests/test-pesel.cpp ${SRC} tests/catch_amalgamated.cpp)
target_include_directories(${PROJECT_NAME}-pesel-ut PUBLIC
    src
)
target_compile_options (${PROJECT_NAME}-pesel-ut PRIVATE ${FLAGS})

add_executable (${PROJECT_NAME}-person-ut tests/test-person.cpp ${SRC} tests/catch_amalgamated.cpp)
target_include_directories(${PROJECT_NAME}-person-ut PUBLIC
    src
)
target_compile_options (${PROJECT_NAME}-person-ut PRIVATE ${FLAGS})

add_executable (${PROJECT_NAME}-student-ut tests/test-student.cpp ${SRC} tests/catch_amalgamated.cpp)
target_include_directories(${PROJECT_NAME}-student-ut PUBLIC
    src
)
target_compile_options (${PROJECT_NAME}-student-ut PRIVATE ${FLAGS})

add_executable (${PROJECT_NAME}-employee-ut tests/test-employee.cpp ${SRC} tests/catch_amalgamated.cpp)
target_include_directories(${PROJECT_NAME}-employee-ut PUBLIC
    src
)
target_compile_options (${PROJECT_NAME}-employee-ut PRIVATE ${FLAGS})

add_executable (${PROJECT_NAME}-universitybase-ut tests/test-universitybase.cpp ${SRC} tests/catch_amalgamated.cpp)
target_include_directories(${PROJECT_NAME}-universitybase-ut PUBLIC
    src
)
target_compile_options (${PROJECT_NAME}-universitybase-ut PRIVATE ${FLAGS})

enable_testing ()
add_test (NAME gender-tests COMMAND ${PROJECT_NAME}-gender-ut)
add_test (NAME pesel-tests COMMAND ${PROJECT_NAME}-pesel-ut)
add_test (NAME person-tests COMMAND ${PROJECT_NAME}-person-ut)
add_test (NAME student-tests COMMAND ${PROJECT_NAME}-student-ut)
add_test (NAME employee-tests COMMAND ${PROJECT_NAME}-employee-ut)
add_test (NAME universitybase-tests COMMAND ${PROJECT_NAME}-universitybase-ut)
