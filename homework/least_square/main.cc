#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include "matrix.h"
#include "qr.h"
#include "lsfit.h"
#include <tuple>

int main() {
    pp::vec x(9), y(9), dy(9);

    double xs[]  = {1,2,3,4,6,9,10,13,15};
    double ys[]  = {117,100,88,72,53,29.5,25.2,15.2,11.1};
    double dys[] = {6,5,4,4,4,3,3,2,2};

    for(int i = 0; i < 9; i++) {
        x[i] = xs[i];
        y[i] = std::log(ys[i]);
        dy[i] = dys[i] / ys[i];
    }

    std::vector<std::function<double(double)>> fs = {
        [](double z) { return 1.0; },
        [](double z) { return z; }
        };


    auto [c, cov] = lsfit(fs, x, y, dy);
    double lambda = -c[1];
    double half_life = std::log(2.0) / lambda;

    std::cerr << "c0 = " << c[0] << "\n";
    std::cerr << "c1 = " << c[1] << "\n";
    std::cerr << "lambda = " << lambda << "\n";
    std::cerr << "half-life = " << half_life << " days\n";

    std::cerr << "covariance matrix:\n";
    for (int i = 0; i < cov.cols(); ++i) {
        for (int j = 0; j < cov.cols(); ++j)
            std::cerr << cov(i, j) << " ";
        std::cerr << "\n";
    }
    double dc0 = std::sqrt(cov(0,0));
    double dc1 = std::sqrt(cov(1,1));

    double dlambda = dc1;

    double T = std::log(2.0)/lambda;
    double dT = std::log(2.0)/(lambda*lambda)*dlambda;

    std::cerr << "dc0 = " << dc0 << "\n";
    std::cerr << "dc1 = " << dc1 << "\n";
    std::cerr << "T_half = " << T << " +/- " << dT << " days\n";
    for(double t = 0; t <= 16; t += 0.1) {
        double fit = std::exp(c[0] + c[1]*t);
        std::cout << t << " " << fit << "\n";
    }
    return 0;
}