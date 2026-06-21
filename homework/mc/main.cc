#include <iostream>
#include <fstream>
#include <cmath>
#include "matrix.h"
#include "mc.h"

int main() {
    pp::vec a2(2), b2(2);
    a2[0] = -1; a2[1] = -1;
    b2[0] =  1; b2[1] =  1;

    auto circle = [](const pp::vec& x) {
        double r2 = x[0]*x[0] + x[1]*x[1];
        return r2 <= 1 ? 1.0 : 0.0;
    };

    std::ofstream circ("circle.data");

    for(int N = 100; N <= 100000; N *= 2) {
        lcg rng(1);
        auto [res, err] = plainmc(circle, a2, b2, N, rng);
        circ << N << " "
            << res << " "
            << err << " "
            << std::abs(res-M_PI) << " "
            << 1/std::sqrt(N)
            << "\n";
    }

    pp::vec a3(3), b3(3);
    a3[0] = -1; a3[1] = -2; a3[2] = -3;
    b3[0] =  1; b3[1] =  2; b3[2] =  3;

    auto ellipsoid = [](const pp::vec& x) {
        double val = x[0]*x[0]/1.0
                   + x[1]*x[1]/4.0
                   + x[2]*x[2]/9.0;

        return val <= 1 ? 1.0 : 0.0;
    };

    std::ofstream ell("ellipsoid.data");
    double exact = 4.0/3.0 * M_PI * 1 * 2 * 3;

    for(int N = 100; N <= 100000; N *= 2) {
        lcg rng(2);
        auto [res, err] = plainmc(ellipsoid, a3, b3, N, rng);
        ell << N << " "
            << res << " "
            << err << " "
            << std::abs(res - exact) << "\n";
    }

    return 0;
}