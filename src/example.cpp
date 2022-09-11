#include "example.hpp"

#include <cmath>
#include <iostream>

namespace GTestExamples {
    double divide(int dividend, int divisor) {
        if (divisor < 1) {
            throw std::runtime_error("Less Than Zero Error");
        }
        return dividend / divisor;
    }

    double square_root(double num) {
        if (num < 0.0) {
            std::cerr << "Less Than Zero Error";
            exit(ERROR_CODE);
        }
        return sqrt(num);
    }
}