#include "sample.hpp"

#include <cmath>
#include "gtest/gtest.h"

namespace GTestExamples {
    namespace DeathTests {
        // Standard Catchall Exit Code https://tldp.org/LDP/abs/html/exitcodes.html
        const int ERROR_CODE = 1;

        double square_root(double num) {
            if (num < 0.0) {
                std::cerr << "Less Than Zero Error";
                exit(ERROR_CODE);
            }
            return sqrt(num);
        }

        TEST(MyDeathTests, SquareRoot) {
            EXPECT_EQ(DeathTests::square_root(0.0), 0.0);
            EXPECT_EQ(DeathTests::square_root(4.0), 2.0);
            EXPECT_DEATH(DeathTests::square_root(-1.0), "Less Than Zero Error");
            EXPECT_EXIT(DeathTests::square_root(-1.0), testing::ExitedWithCode(DeathTests::ERROR_CODE),
                        "Less Than Zero");
        }
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
