#pragma once
#include "matrix.h"

struct ann {
    int n;
    pp::vec p;

    ann(int n);

    double f(double x) const;
    double response(double x) const;
    void train(const pp::vec& xs, const pp::vec& ys);
};