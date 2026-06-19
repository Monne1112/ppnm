#pragma once
#include <vector>
#include <functional>
#include "matrix.h"
#include <tuple>

std::tuple<pp::vec, pp::mat> lsfit(
    const std::vector<std::function<double(double)>>& fs,
    const pp::vec& x,
    const pp::vec& y,
    const pp::vec& dy
);