cmake_minimum_required(VERSION 3.28.3)
project(SudokuSolver VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4 /WX)
endif()

include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)
list(FILTER APP_SOURCES EXCLUDE REGEX "src/main.cpp")

add_executable(SudokuSolver src/main.cpp ${APP_SOURCES})

if (UNIX)
    target_link_libraries(SudokuSolver pthread)
endif()


enable_testing()
add_subdirectory(tests)