#include "Solver.hpp"

Solver::Solver(SudokuBoard &sb)
{
    this->sb = sb;
}

void Solver::solve()
{
    int status = trySolveFromPoint(findNextZero());
    if (status != 0)
    {
        throw std::runtime_error("Could not solve board");
    }

    sb.displayBoard();
}

Point Solver::findNextZero()
{
    printf("here\n");
    fflush(stdout);
    for (int i = 0; i < 81; i++)
    {
        int x = i % 9;
        int y = i / 9;
        if (this->sb.getValue(x, y) == 0)
        {
            Point p;
            p.x = x;
            p.y = y;
            return p;
        }
    }

    Point p;
    p.x = -1;
    p.y = -1;
    return p;
}

int Solver::trySolveFromPoint(Point p)
{
    // Generate list of possible solutions for point
    // Iterate list
    // Implement item, find next zero, call
    // If item fails, undo, try next item

    printf("p.x %d\n p.y %d\n\n", p.x, p.y);
    fflush(stdout);

    if (p.x == -1 || p.y == -1)
    {
        return 0;
    }

    if (this->sb.getValue(p.x, p.y) != 0)
    {
        throw std::runtime_error("trySolveFromPoint given non-zero Point");
    }

    bool possibilities[9];
    std::fill_n(possibilities, 9, true);

    // Wipe from row
    for (int i = 0; i < 9; i++)
    {
        int val = this->sb.getValue(i, p.y);
        if (val == 0) continue;
        possibilities[val-1] = false;
    }

    // Wipe from col
    for (int i = 0; i < 9; i++)
    {
        int val = this->sb.getValue(p.x, i);
        if (val == 0) continue;
        possibilities[val-1] = false;
    }

    // Wipe from 3x3 cell
    int cellX = p.x / 3;
    int cellY = p.y / 3;
    for (int xOffset = 0; xOffset < 3; xOffset++)
    {
        for (int yOffset = 0; yOffset < 3; yOffset++)
        {
            int coordX = cellX * 3 + xOffset;
            int coordY = cellY * 3 + yOffset;

            int val = this->sb.getValue(coordX, coordY);
            if (val == 0) continue;
            possibilities[val-1] = false;
        }
    }

    for (int possibility = 0; possibility < 9; possibility++)
    {
        if (possibilities[possibility])
        {
            this->sb.setValue(p.x, p.y, possibility+1);

            int status = this->trySolveFromPoint(this->findNextZero());
            if (status == 0)
            {
                return 0;
            }

            this->sb.setValue(p.x, p.y, 0);
        }
    }

    return -1;
}