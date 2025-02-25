#include <gtest/gtest.h>
#include "SudokuBoard.hpp"

TEST(TestSudokuBoard, TestConstructor)
{
    SudokuBoard sb;

    for (int i = 0; i < 81; i++)
    {
        int x = i % 9;
        int y = i / 9;

        ASSERT_EQ(0, sb.getValue(x, y));
    }
}

TEST(TestSudokuBoard, TestSetValue)
{
    SudokuBoard sb;

    ASSERT_NO_THROW(sb.setValue(3, 3, 3));
    ASSERT_EQ(3, sb.getValue(3, 3));

    ASSERT_NO_THROW(sb.setValue(5, 5, 6));
    ASSERT_EQ(6, sb.getValue(5, 5));

    ASSERT_THROW(sb.setValue(5, 5, 10), std::runtime_error);
    ASSERT_THROW(sb.setValue(5, 5, -4), std::runtime_error);
    ASSERT_THROW(sb.setValue(-5, 5, 5), std::runtime_error);
    ASSERT_THROW(sb.setValue(15, 5, 5), std::runtime_error);
    ASSERT_THROW(sb.setValue(5, -5, 5), std::runtime_error);
    ASSERT_THROW(sb.setValue(5, 15, 5), std::runtime_error);
}

TEST(TestSudokuBoard, TestToString)
{
    SudokuBoard sb;

    ASSERT_STREQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000", sb.toString().c_str());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}