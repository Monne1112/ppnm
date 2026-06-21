#include <iostream>
#include <fstream>
#include <cmath>
#include "integrate.h"

int main() {
    auto f1 = [](double x){ return std::sqrt(x); };
    auto f2 = [](double x){ return 1/std::sqrt(x); };
    auto f3 = [](double x){ return std::sqrt(1-x*x); };
    auto f4 = [](double x){ return std::log(x)/std::sqrt(x); };

    std::cerr << "sqrt(x): " << integrate(f1,0,1) << " exact " << 2.0/3 << "\n";
    std::cerr << "1/sqrt(x): " << integrate(f2,0,1) << " exact " << 2.0 << "\n";
    std::cerr << "sqrt(1-x^2): " << integrate(f3,0,1) << " exact " << M_PI/4 << "\n";
    std::cerr << "ln(x)/sqrt(x): " << integrate(f4,0,1) << " exact " << -4.0 << "\n";

    std::ofstream erfout("erf.data");
    for(double z=-3; z<=3; z+=0.05)
        erfout << z << " " << erf_integral(z) << " " << std::erf(z) << "\n";

    std::ofstream accout("acc.data");
    double exact = 0.8427007929497149;

    for(double acc=1e-1; acc>=1e-8; acc/=10) {
        auto f = [](double x){ return std::exp(-x*x); };
        double val = 2/std::sqrt(M_PI)*integrate(f,0,1,acc,0);
        accout << acc << " " << std::abs(val-exact) << "\n";
    }

    return 0;
}