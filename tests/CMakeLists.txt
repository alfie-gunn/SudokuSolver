include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    *.cpp
)

add_executable(SudokuSolverTests ${TEST_SOURCES} ${APP_SOURCES})

target_link_libraries(SudokuSolverTests PRIVATE gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(SudokuSolverTests)