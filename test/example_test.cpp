#include "example.hpp"

#include "gtest/gtest.h"

/**\file example_test.cc
 *
 * \test Example Tests
 *
 * Examples of Google Test [Exception Assertions](https://google.github.io/googletest/reference/assertions.html#exceptions),
 * [Death Tests](https://github.com/google/googletest/blob/main/docs/advanced.md#user-content-death-tests)
 *
 *  * Type   | Test Name          | Description
 * :-------- | :----------------- | :---------
 * Exception | LessThanZeroThrows | Validate square_root throws exception on less than zero
 *
 */
namespace GTestExamples {
    TEST(DivideTests, Positive) {
        EXPECT_EQ(GTestExamples::divide(2, 1), 2.0);
        EXPECT_EQ(GTestExamples::divide(0, 4), 0.0);
    }

    TEST(DivideTests, LessThanZeroThrows) {
        EXPECT_ANY_THROW(GTestExamples::divide(5, 0));
        EXPECT_THROW(GTestExamples::divide(3, -2), std::runtime_error);
    }

    TEST(SquareRootTests, Positive) {
        EXPECT_EQ(GTestExamples::square_root(0.0), 0.0);
        EXPECT_EQ(GTestExamples::square_root(4.0), 2.0);
    }

    TEST(SquareRootTests, LessThanOneCausesDeath) {
        EXPECT_DEATH(GTestExamples::square_root(-1.0), "Less Than Zero Error");
        EXPECT_EXIT(GTestExamples::square_root(-1.0), testing::ExitedWithCode(GTestExamples::ERROR_CODE),
                    "Less Than Zero");
    }

    // Example of positive tests does as parameterized tests.

    class SquareRoot_Param_Test : public ::testing::TestWithParam<std::tuple<double, double>> {
    };

    INSTANTIATE_TEST_SUITE_P(SquareRoot_Param_Test_Instantiate,
                             SquareRoot_Param_Test,
                             testing::Values(
                                     std::make_tuple(0.0, 0.0),
                                     std::make_tuple(2.0, 4.0)
                             ));

    TEST_P(SquareRoot_Param_Test, Param_Positive) {
        double expected = std::get<0>(GetParam());
        double i = std::get<1>(GetParam());

        EXPECT_EQ(expected, GTestExamples::square_root(i));
    }

    // Example of negative tests does as parameterized tests.

    class SquareRoot_ParamNegative_Test : public ::testing::TestWithParam<double> {
    };

    TEST_P(SquareRoot_ParamNegative_Test, Param_Negative) {
        EXPECT_DEATH(GTestExamples::square_root(GetParam()), "Less Than Zero Error");
        EXPECT_EXIT(GTestExamples::square_root(GetParam()), testing::ExitedWithCode(GTestExamples::ERROR_CODE),
                    "Less Than Zero");
    }

    INSTANTIATE_TEST_SUITE_P(SquareRoot_ParamNegative_Test_Instantiate,
                             SquareRoot_ParamNegative_Test,
                             testing::Values(-1.0, -5.0));

}
