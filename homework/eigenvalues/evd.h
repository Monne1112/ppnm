#pragma once
#include "matrix.h"

namespace pp {

struct EVD {
    vec w;
    mat V;

    static void timesJ(mat& A, int p, int q, double theta);
    static void Jtimes(mat& A, int p, int q, double theta);

    EVD(mat A);
};

}