#include "SudokuBoard.hpp"

SudokuBoard::SudokuBoard()
{
    this->boardValues = new int*[9];
    for (int y = 0; y < 9; y++)
    {
        this->boardValues[y] = new int[9];
        for (int x = 0; x < 9; x++)
        {
            this->setValue(x, y, 0);
        }
    }

}

SudokuBoard::~SudokuBoard()
{
    for (int y = 0; y < 9; y++)
    {
        delete this->boardValues[y];
    }

    delete this->boardValues;
}

void SudokuBoard::setValue(int x, int y, int value)
{
    if (value >= 9 || value < 0)
    {
        throw std::runtime_error("value exceeds bounds");
    }

    this->boardValues[y][x] = value;
}

int SudokuBoard::getValue(int x, int y)
{
    return this->boardValues[y][x];
}