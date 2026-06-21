#include "roots.h"
#include "qr.h"
#include <cmath>

pp::mat jacobian(
    std::function<pp::vec(pp::vec)> f,
    pp::vec x,
    pp::vec fx
) {
    int n = x.size();
    pp::mat J(n,n);

    for(int j = 0; j < n; j++) {
        double dx = std::max(std::abs(x[j]), 1.0) * std::pow(2,-26);

        x[j] += dx;
        pp::vec dfx = f(x) - fx;
        x[j] -= dx;

        for(int i = 0; i < n; i++)
            J(i,j) = dfx[i]/dx;
    }

    return J;
}

pp::vec newton(
    std::function<pp::vec(pp::vec)> f,
    pp::vec x,
    double acc,
    double alpha_min,
    int max_iter
) {
    pp::vec fx = f(x);

    for(int iter = 0; iter < max_iter; iter++) {
        if(pp::norm(fx) < acc)
            break;

        pp::mat J = jacobian(f,x,fx);
        pp::qr QRJ(J);

        pp::vec minus_fx(fx.size());
        for(int i = 0; i < fx.size(); i++)
            minus_fx[i] = -fx[i];

        pp::vec Dx = QRJ.solve(minus_fx);

        double alpha = 1.0;
        pp::vec z;
        pp::vec fz;

        while(true) {
            z = x + alpha*Dx;
            fz = f(z);

            if(pp::norm(fz) < pp::norm(fx))
                break;

            if(alpha < alpha_min)
                break;

            alpha /= 2;
        }

        x = z;
        fx = fz;

        //if(pp::norm(Dx)*alpha < acc)
         //   break;
    }

    return x;
}