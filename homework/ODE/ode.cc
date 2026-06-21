#include "ode.h"
#include <cmath>
#include <algorithm>

std::tuple<pp::vec, pp::vec> rkstep12(
    std::function<pp::vec(double, pp::vec)> f,// function that computes the derivative
    double x, // current x value
    pp::vec y, // current y value
    double h // step size
) {
    pp::vec k0 = f(x,y); 
    pp::vec k1 = f(x+h/2, y + k0*(h/2));

    pp::vec yh = y + k1*h;
    pp::vec err = (k1-k0)*h;

    return std::make_tuple(yh, err);
}

std::tuple<std::vector<double>, std::vector<pp::vec>> driver(
    std::function<pp::vec(double, pp::vec)> f,
    double a,
    double b,
    pp::vec yinit,
    double h,
    double acc,
    double eps
) {
    double x = a;
    pp::vec y = yinit;

    std::vector<double> xs;
    std::vector<pp::vec> ys;

    xs.push_back(x);
    ys.push_back(y);

    while(x < b) {
        if(x + h > b) h = b - x;

        auto [yh, err] = rkstep12(f, x, y, h);

        double tol = (acc + eps*pp::norm(yh)) * std::sqrt(h/(b-a));
        double e = pp::norm(err);

        if(e <= tol) {
            x += h;
            y = yh;
            xs.push_back(x);
            ys.push_back(y);
        }

        if(e > 0)
            h *= std::min(std::pow(tol/e, 0.25)*0.95, 2.0);
        else
            h *= 2;
    }

    return std::make_tuple(xs, ys);
}