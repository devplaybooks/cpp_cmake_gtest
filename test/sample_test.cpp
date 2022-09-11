#include "sample.hpp"

#include <cmath>
#include "gtest/gtest.h"

// Standard Catchall Exit Code https://tldp.org/LDP/abs/html/exitcodes.html
const int ERROR_CODE = 1;

namespace GTestExamples {
    double square_root(double num) {
        if (num < 0.0) {
            std::cerr << "Less Than Zero Error";
            exit(ERROR_CODE);
        }
        return sqrt(num);
    }

    TEST(SquareRootTests, Positive) {
        EXPECT_EQ(GTestExamples::square_root(0.0), 0.0);
        EXPECT_EQ(GTestExamples::square_root(4.0), 2.0);
    }

    TEST(SquareRootTests, LessThanOneCausesDeath) {
        EXPECT_DEATH(GTestExamples::square_root(-1.0), "Less Than Zero Error");
        EXPECT_EXIT(GTestExamples::square_root(-1.0), testing::ExitedWithCode(ERROR_CODE),
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

namespace {
// In this example, we test the MyString class (a simple string).

// Tests the default c'tor.
    TEST(MyString, DefaultConstructor) {
        const MyString s;
        EXPECT_STREQ(nullptr, s.c_string());

        EXPECT_EQ(0u, s.Length());
    }

    const char kHelloString[] = "Hello, world!";

// Tests the c'tor that accepts a C string.
    TEST(MyString, ConstructorFromCString) {
        const MyString s(kHelloString);

        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));
        EXPECT_EQ(sizeof(kHelloString) / sizeof(kHelloString[0]) - 1, s.Length());
    }

// Tests the copy c'tor.
    TEST(MyString, CopyConstructor) {
        const MyString s1(kHelloString);

        const MyString s2 = s1;

        EXPECT_EQ(0, strcmp(s2.c_string(), kHelloString));
    }

// Tests the Set method.
    TEST(MyString, SetSimple) {
        MyString s;

        s.Set(kHelloString);

        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));
    }

// Tests the Set method.
    TEST(MyString, Set) {
        MyString s;

        s.Set(kHelloString);

        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));

        // Set should work when the input pointer is the same as the one
        // already in the MyString object.
        s.Set(s.c_string());
        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));
    }

// Tests the Set method.
    TEST(MyString, SetNullPtr) {
        MyString s;
        s.Set(kHelloString);

        s.Set(nullptr);

        EXPECT_STREQ(nullptr, s.c_string());
    }
}  // namespace
