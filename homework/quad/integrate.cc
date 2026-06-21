#include "integrate.h"
#include <cmath>

double integrate(
    std::function<double(double)> f,
    double a,
    double b,
    double acc,
    double eps,
    double f2,
    double f3
) {
    double h = b-a;

    if(std::isnan(f2)) {
        f2 = f(a + 2*h/6);
        f3 = f(a + 4*h/6);
    }

    double f1 = f(a + h/6);
    double f4 = f(a + 5*h/6);

    double Q = (2*f1 + f2 + f3 + 2*f4)/6*h;
    double q = (f1 + f2 + f3 + f4)/4*h;

    double err = std::abs(Q-q);
    double tol = acc + eps*std::abs(Q);

    if(err < tol)
        return Q;

    double mid = (a+b)/2;

    return integrate(f,a,mid,acc/std::sqrt(2),eps,f1,f2)
         + integrate(f,mid,b,acc/std::sqrt(2),eps,f3,f4);
}

double erf_integral(double z) {
    if(z < 0)
        return -erf_integral(-z);

    if(z <= 1) {
        auto f = [](double x) {
            return std::exp(-x*x);
        };

        return 2/std::sqrt(M_PI) * integrate(f,0,z,1e-6,1e-6);
    }

    auto f = [z](double t) {
        double x = z + (1-t)/t;
        return std::exp(-x*x)/(t*t);
    };

    return 1 - 2/std::sqrt(M_PI)*integrate(f,0,1,1e-6,1e-6);
}