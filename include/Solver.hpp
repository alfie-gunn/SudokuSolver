#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <stack>

#include "SudokuBoard.hpp"

struct point
{
    int x;
    int y;
} typedef Point;

class Solver
{
private:
    SudokuBoard sb;

    Point findNextZero();
    int trySolveFromPoint(Point p);

public:
    Solver(SudokuBoard &sb);

    void solve();
};

#endif // SOLVER_HPP