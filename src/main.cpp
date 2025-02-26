#include <stdio.h>
#include <iostream>
#include "SudokuBoard.hpp"
#include "Solver.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Argc = %d, not 2\n", argc);
        return 1;
    }

    SudokuBoard sb;

    try
    {
        sb = SudokuBoard(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
        return 1;
    }

    Solver s(sb);
    s.solve();

    return 0;
}