#include "SudokuBoard.hpp"

SudokuBoard::SudokuBoard()
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            this->setValue(x, y, 0);
        }
    }
}

SudokuBoard::SudokuBoard(char *source)
{
    SudokuBoard();
    this->fromString(source);
}

void SudokuBoard::setValue(int x, int y, int value)
{
    if (value > 9 || value < 0)
    {
        throw std::runtime_error("value exceeds bounds");
    }

    if (x >= 9 || x < 0)
    {
        throw std::runtime_error("x exceeds bounds");
    }

    if (y >= 9 || y < 0)
    {
        throw std::runtime_error("y exceeds bounds");
    }

    this->boardValues[y][x] = value;
}

int SudokuBoard::getValue(int x, int y)
{
    if (x >= 9 || x < 0)
    {
        throw std::runtime_error("x exceeds bounds");
    }

    if (y >= 9 || y < 0)
    {
        throw std::runtime_error("y exceeds bounds");
    }

    return this->boardValues[y][x];
}

void SudokuBoard::fromString(char *source)
{
    int lengthCounter = 0;

    for (int i = 0; source[i] != '\0'; i++)
    {
        lengthCounter++;
        if (lengthCounter > 81)
        {
            throw std::runtime_error("Source input exceeds 81 char limit");
        }

        char c = source[i];
        int x = i % 9;
        int y = i / 9;
        int num = c - '0';

        if (num < 0 || num > 9)
        {
            throw std::runtime_error("Num exceeds limits: 0, 9 inclusive");
        }
        else
        {
            this->setValue(x, y, num);
        }
    }

    if (lengthCounter < 81)
    {
        throw std::runtime_error("Source input does not meet 81 char requirement");
    }
}

std::string SudokuBoard::toString()
{
    std::stringstream ss;

    for (int i = 0; i < 81; i++)
    {
        int x = i % 9;
        int y = i / 9;

        ss << this->getValue(x, y);
    }

    return ss.str();
}