#include <gtest/gtest.h>
#include "Hello.hpp"

class HelloTest : public testing::Test {};

TEST_F(HelloTest, ConstructHello)
{
    Hello* h = new Hello();
    ASSERT_NE(h, nullptr);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}