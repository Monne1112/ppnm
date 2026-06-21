#include <iostream>
#include <cmath>
#include "matrix.h"
#include "qr.h"
#include "minim.h"

int main() {
    auto rosen = [](pp::vec x) {
        double X = x[0], Y = x[1];
        return (1-X)*(1-X) + 100*(Y-X*X)*(Y-X*X);
    };

    pp::vec xr(2);
    xr[0] = -1;
    xr[1] = 2;

    std::cerr << "Rosenbrock:\n";
    pp::vec rr = newton_minimize(rosen,xr);
    std::cout << "minimum = " << rr[0] << " " << rr[1] << "\n";
    std::cout << "f(min) = " << rosen(rr) << "\n\n";


    auto himmel = [](pp::vec x) {
        double X = x[0], Y = x[1];
        return (X*X + Y - 11)*(X*X + Y - 11)
             + (X + Y*Y - 7)*(X + Y*Y - 7);
    };

    pp::vec xh(2);
    xh[0] = 3;
    xh[1] = 2;

    std::cerr << "Himmelblau:\n";
    pp::vec rh = newton_minimize(himmel,xh);
    std::cout << "minimum = " << rh[0] << " " << rh[1] << "\n";
    std::cout << "f(min) = " << himmel(rh) << "\n";

    return 0;
}