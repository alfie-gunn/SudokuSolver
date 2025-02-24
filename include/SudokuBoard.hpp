#ifndef SUDOKUBOARD_HPP
#define SUDOKUBOARD_HPP

#include <stdexcept>

class SudokuBoard {
private:
    int **boardValues;
public:
    SudokuBoard();
    ~SudokuBoard();

    void setValue(int x, int y, int value);
    int getValue(int x, int y);
};

#endif // SUDOKUBOARD_HPP  