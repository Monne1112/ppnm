#include "mc.h"
#include <cmath>
#include <cstdint>

double lcg::operator()() {
    seed = 1664525u*seed + 1013904223u;
    return (double(seed) + 1.0) / (double(UINT32_MAX) + 2.0);
}

std::tuple<double,double> plainmc(
    std::function<double(const pp::vec&)> f,
    const pp::vec& a,
    const pp::vec& b,
    int N,
    lcg& rng
) {
    int dim = a.size();

    double V = 1;
    for(int i=0;i<dim;i++)
        V *= b[i] - a[i];

    double sum = 0;
    double sum2 = 0;

    pp::vec x(dim);

    for(int i=0;i<N;i++) {
        for(int k=0;k<dim;k++)
            x[k] = a[k] + rng()*(b[k]-a[k]);

        double fx = f(x);
        sum += fx;
        sum2 += fx*fx;
    }

    double mean = sum/N;
    double sigma = std::sqrt(sum2/N - mean*mean);

    return std::make_tuple(mean*V, sigma*V/std::sqrt(N));
}