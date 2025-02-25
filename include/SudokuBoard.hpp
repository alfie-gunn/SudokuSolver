#ifndef SUDOKUBOARD_HPP
#define SUDOKUBOARD_HPP

#include <stdexcept>
#include <sstream>

class SudokuBoard {
private:
    int boardValues[9][9];
    void fromString(std::string& source);

public:
    SudokuBoard();
    ~SudokuBoard();

    void setValue(int x, int y, int value);
    int getValue(int x, int y);

    std::string toString();
};

#endif // SUDOKUBOARD_HPP  