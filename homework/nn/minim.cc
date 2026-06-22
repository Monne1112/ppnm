#include "minim.h"
#include "qr.h"
#include <cmath>
#include <iostream>

pp::vec gradient(std::function<double(pp::vec)> phi, pp::vec x) {
    int n = x.size();
    pp::vec g(n);

    double phix = phi(x);

    for(int i = 0; i < n; i++) {
        double dx = (1 + std::abs(x[i])) * std::pow(2,-26);

        x[i] += dx;
        g[i] = (phi(x) - phix)/dx;
        x[i] -= dx;
    }

    return g;
}

pp::mat hessian(std::function<double(pp::vec)> phi, pp::vec x) {
    int n = x.size();
    pp::mat H(n,n);

    pp::vec gx = gradient(phi,x);

    for(int j = 0; j < n; j++) {
        double dx = (1 + std::abs(x[j])) * std::pow(2,-13);

        x[j] += dx;
        pp::vec dg = gradient(phi,x) - gx;
        x[j] -= dx;

        for(int i = 0; i < n; i++)
            H(i,j) = dg[i]/dx;
    }

    return H;
}

pp::vec newton_minimize(
    std::function<double(pp::vec)> phi,
    pp::vec x,
    double acc,
    int max_iter
) {
    for(int iter = 0; iter < max_iter; iter++) {
        pp::vec g = gradient(phi,x);

        if(pp::norm(g) < acc) {
            std::cerr << "steps = " << iter << "\n";
            return x;
        }

        pp::mat H = hessian(phi,x);

        for(int i = 0; i < H.rows(); i++)
            H(i,i) += 1e-6;

        pp::qr QRH(H);

        pp::vec minus_g(g.size());
        for(int i = 0; i < g.size(); i++)
            minus_g[i] = -g[i];

        pp::vec dx = QRH.solve(minus_g);

        double lambda = 1.0;
        double phix = phi(x);

        while(lambda >= 1.0/1024) {
            pp::vec z = x + lambda*dx;

            if(phi(z) < phix)
                break;

            lambda /= 2;
        }

        x = x + lambda*dx;
    }

    std::cerr << "max_iter reached\n";
    return x;
}