#include <iostream>
#include <fstream>
#include <cmath>
#include "matrix.h"
#include "ode.h"

int main() {
    auto F = [](double x, pp::vec y) {
        pp::vec dydx(2);
        dydx[0] = y[1];
        dydx[1] = -y[0];
        return dydx;
    };

    pp::vec y0(2);
    y0[0] = 1;
    y0[1] = 0;

    auto [xs, ys] = driver(F, 0, 10, y0, 0.1, 1e-4, 1e-4);

    std::ofstream out("oscillator.data");

    for(size_t i=0;i<xs.size();i++) {
        double x = xs[i];
        double u = ys[i][0];

        out << x << " "
            << u << " "
            << std::cos(x) << " "
            << u-std::cos(x) << "\n";
    }

    auto damped = [](double x, pp::vec y) {
        double gamma = 0.15;

        pp::vec dydx(2);
        dydx[0] = y[1];
        dydx[1] = -y[0] - gamma*y[1];

        return dydx;
    };

    pp::vec yd0(2);
    yd0[0] = 1;
    yd0[1] = 0;

    auto [xd, yd] = driver(damped, 0, 30, yd0, 0.1, 1e-4, 1e-4);

    std::ofstream damped_out("damped.data");
    for(size_t i = 0; i < xd.size(); i++) {
        damped_out << xd[i] << " " << yd[i][0] << "\n";
    }
    return 0;
}