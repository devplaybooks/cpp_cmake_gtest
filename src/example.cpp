#include "example.hpp"

#include <cmath>
#include <iostream>

namespace GTestExamples {
    double square_root(double num) {
        if (num < 0.0) {
            std::cerr << "Less Than Zero Error";
            exit(ERROR_CODE);
        }
        return sqrt(num);
    }
}