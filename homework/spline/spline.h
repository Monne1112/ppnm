#pragma once
#include "matrix.h"

int binsearch(const pp::vec& x, double z);

double linterp(
    const pp::vec& x,
    const pp::vec& y,
    double z
);

double linterpInteg(
    const pp::vec& x,
    const pp::vec& y,
    double z
);