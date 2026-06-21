#pragma once
#include <functional>
#include "matrix.h"

pp::mat jacobian(
    std::function<pp::vec(pp::vec)> f,
    pp::vec x,
    pp::vec fx
);

pp::vec newton(
    std::function<pp::vec(pp::vec)> f,
    pp::vec x,
    double acc = 1e-6,
    double alpha_min = 1.0/64,
    int max_iter = 100
);