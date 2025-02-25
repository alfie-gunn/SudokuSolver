#ifndef SUDOKUBOARD_HPP
#define SUDOKUBOARD_HPP

#include <stdexcept>
#include <sstream>

class SudokuBoard {
private:
    int boardValues[9][9];

public:
    SudokuBoard();
    SudokuBoard(std::string& source);
    SudokuBoard(char* source);

    void setValue(int x, int y, int value);
    int getValue(int x, int y);

    std::string toString();
    void fromString(char* source);
};

#endif // SUDOKUBOARD_HPP  