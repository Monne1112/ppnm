#pragma once
#include "matrix.h"

struct qspline {
    pp::vec x, y, b, c;
    int n;

    qspline(const pp::vec& xs, const pp::vec& ys);

    int binsearch(double z) const;
    double eval(double z) const;
    double deriv(double z) const;
    double integ(double z) const;
};