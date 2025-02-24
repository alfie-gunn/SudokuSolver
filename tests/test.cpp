#include <gtest/gtest.h>
#include "SudokuBoard.hpp"

TEST(TestSudokuBoard, TestConstructor)
{
    SudokuBoard* sb = new SudokuBoard();

    for (int i = 0; i < 81; i++)
    {
        int x = i % 9;
        int y = i / 9;

        ASSERT_EQ(0, sb->getValue(x, y));
    }

    delete sb;
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}