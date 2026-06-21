#pragma once
#include <functional>
#include "matrix.h"

pp::vec gradient(std::function<double(pp::vec)> phi, pp::vec x);

pp::mat hessian(std::function<double(pp::vec)> phi, pp::vec x);

pp::vec newton_minimize(
    std::function<double(pp::vec)> phi,
    pp::vec x,
    double acc = 1e-3,
    int max_iter = 1000
);