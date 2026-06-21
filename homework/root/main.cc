#include <iostream>
#include <cmath>
#include "matrix.h"
#include "qr.h"
#include "roots.h"

int main() {
    auto f1 = [](pp::vec x) {
        pp::vec y(1);
        y[0] = x[0]*x[0] - 2;
        return y;
    };

    pp::vec x1(1);
    x1[0] = 1;

    pp::vec r1 = newton(f1, x1);
    std::cout << "sqrt(2) root:\n";
    std::cout << r1[0] << "\n";
    std::cout << "f(root) = " << f1(r1)[0] << "\n\n";


    auto rosen_grad = [](pp::vec x) {
        double X = x[0];
        double Y = x[1];

        pp::vec g(2);
        g[0] = -2*(1-X) - 400*X*(Y-X*X);
        g[1] = 200*(Y-X*X);

        return g;
    };

    pp::vec xr(2);
    xr[0] = -1;
    xr[1] = 2;

    pp::vec rr = newton(rosen_grad, xr, 1e-6, 1.0/64, 10000);
    std::cout << "Rosenbrock minimum:\n";
    std::cout << rr[0] << " " << rr[1] << "\n";
    pp::vec gr = rosen_grad(rr);
    std::cout << "gradient norm = " << pp::norm(gr) << "\n\n";


    auto himmel_grad = [](pp::vec x) {
        double X = x[0];
        double Y = x[1];

        pp::vec g(2);
        g[0] = 4*X*(X*X + Y - 11) + 2*(X + Y*Y - 7);
        g[1] = 2*(X*X + Y - 11) + 4*Y*(X + Y*Y - 7);

        return g;
    };

    pp::vec h0(2);
    h0[0] = 3;
    h0[1] = 2;

    pp::vec rh = newton(himmel_grad, h0);
    std::cout << "Himmelblau minimum from (3,2):\n";
    std::cout << rh[0] << " " << rh[1] << "\n";
    pp::vec gh = himmel_grad(rh);
    std::cout << "gradient norm = " << pp::norm(gh) << "\n";

    return 0;
}