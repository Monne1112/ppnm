#pragma once
#include <functional>
#include <tuple>

double integrate(
    std::function<double(double)> f,
    double a,
    double b,
    double acc = 1e-3,
    double eps = 1e-3,
    double f2 = __builtin_nan(""),
    double f3 = __builtin_nan("")
);

double erf_integral(double z);