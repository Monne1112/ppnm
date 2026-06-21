#pragma once
#include <functional>
#include <tuple>
#include "matrix.h"

struct lcg {
    unsigned int seed;
    lcg(unsigned int seed=1) : seed(seed) {}

    double operator()();
};

std::tuple<double,double> plainmc(
    std::function<double(const pp::vec&)> f,
    const pp::vec& a,
    const pp::vec& b,
    int N,
    lcg& rng
);