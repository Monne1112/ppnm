#include "ann.h"
#include "minim.h"
#include <cmath>

ann::ann(int n) : n(n), p(3*n) {
    for(int i = 0; i < n; i++) {
        p[3*i+0] = -1.0 + 2.0*i/(n-1); // a_i
        p[3*i+1] = 0.4;                // b_i
        p[3*i+2] = 2;                // w_i
    }
}

double ann::f(double x) const {
    return x*std::exp(-x*x); // Gaussian wavelet
}

double ann::response(double x) const {
    double sum = 0;

    for(int i = 0; i < n; i++) {
        double a = p[3*i+0];
        double b = p[3*i+1];
        double w = p[3*i+2];

        double z = (x-a)/b;
        sum += f(z)*w;
    }

    return sum;
}

void ann::train(const pp::vec& xs, const pp::vec& ys) {
    auto cost = [&](pp::vec q) {
        pp::vec old = p;
        p = q;

        double sum = 0;
        for(int k = 0; k < xs.size(); k++) {
            double diff = response(xs[k]) - ys[k];
            sum += diff*diff;
        }

        p = old;
        return sum;
    };

    p = newton_minimize(cost, p, 1e-4, 150);
}