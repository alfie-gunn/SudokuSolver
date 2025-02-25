#include <gtest/gtest.h>
#include "SudokuBoard.hpp"

class SudokuBoardBasicTest : public testing::Test
{
protected:
    SudokuBoard sb;
};

TEST_F(SudokuBoardBasicTest, TestConstructor)
{
    for (int i = 0; i < 81; i++)
    {
        int x = i % 9;
        int y = i / 9;

        ASSERT_EQ(0, sb.getValue(x, y));
    }
}

TEST_F(SudokuBoardBasicTest, TestSetValue)
{
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

TEST_F(SudokuBoardBasicTest, TestToString)
{
    // Add tests for invalid inputs
    ASSERT_STREQ("000000000000000000000000000000000000000000000000000000000000000000000000000000000", sb.toString().c_str());
    sb.setValue(5, 5, 5);
    ASSERT_STRNE("000000000000000000000000000000000000000000000000000000000000000000000000000000000", sb.toString().c_str());
    ASSERT_STREQ("000000000000000000000000000000000000000000000000005000000000000000000000000000000", sb.toString().c_str());
}

TEST_F(SudokuBoardBasicTest, TestFromString)
{
    char validInput[] = "123456080897435678234598234659823745638924756912874061578413845891345690387456234";
    ASSERT_NO_THROW(sb.fromString(validInput));

    ASSERT_EQ(sb.getValue(0, 0), 1);
    ASSERT_EQ(sb.getValue(2, 0), 3);
    ASSERT_EQ(sb.getValue(0, 1), 8);

    char tooShortInput[] = "230847";
    ASSERT_THROW(sb.fromString(tooShortInput), std::runtime_error);

    char tooLongInput[] = "1234567808974356782345982346598237456389247569128740615784138458913456903874562345";
    ASSERT_THROW(sb.fromString(tooLongInput), std::runtime_error);

    char invalidCharsInput[] = "aofsi6780897435678234598234659823745638924756912874061578413845891345690387456234";
    ASSERT_THROW(sb.fromString(invalidCharsInput), std::runtime_error);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}