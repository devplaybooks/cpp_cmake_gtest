#include "example.hpp"

#include "gtest/gtest.h"

namespace GTestExamples {
    TEST(SquareRootTests, Positive) {
        EXPECT_EQ(GTestExamples::square_root(0.0), 0.0);
        EXPECT_EQ(GTestExamples::square_root(4.0), 2.0);
    }

    TEST(SquareRootTests, LessThanOneCausesDeath) {
        EXPECT_DEATH(GTestExamples::square_root(-1.0), "Less Than Zero Error");
        EXPECT_EXIT(GTestExamples::square_root(-1.0), testing::ExitedWithCode(GTestExamples::ERROR_CODE),
                    "Less Than Zero");
    }

    double divide(int dividend, int divisor) {
        if (divisor < 1) {
            throw std::runtime_error("Less Than Zero Error");
        }
        return dividend / divisor;
    }

    TEST(DivideTests, Positive) {
        EXPECT_EQ(GTestExamples::divide(2, 1), 2.0);
        EXPECT_EQ(GTestExamples::divide(0, 4), 0.0);
    }

    TEST(DivideTests, LessThanZeroThrows) {
        EXPECT_ANY_THROW(GTestExamples::divide(5, 0));
        EXPECT_THROW(GTestExamples::divide(3 , -2), std::runtime_error);
    }
}
