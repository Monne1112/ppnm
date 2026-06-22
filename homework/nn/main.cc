#include <iostream>
#include <fstream>
#include <cmath>
#include "matrix.h"
#include "ann.h"

int main() {
    int N = 25;
    pp::vec xs(N), ys(N);

    auto target = [](double x) {
        return std::cos(5*x - 1)*std::exp(-x*x);
    };

    for(int i = 0; i < N; i++) {
        xs[i] = -1.0 + 2.0*i/(N-1);
        ys[i] = target(xs[i]);
    }

    ann net(3);
    net.train(xs,ys);

    std::ofstream data("ann.data");

    for(double x = -1; x <= 1; x += 0.01) {
        data << x << " "
             << net.response(x) << " "
             << target(x) << "\n";
    }

    std::ofstream points("points.data");
    for(int i = 0; i < N; i++)
        points << xs[i] << " " << ys[i] << "\n";

    return 0;
}