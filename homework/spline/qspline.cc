#include "qspline.h"
#include "matrix.h"
#include <cassert>
qspline::qspline(const pp::vec& xs, const pp::vec& ys)
    : x(xs), y(ys), b(xs.size()-1), c(xs.size()-1), n(xs.size())
{
    pp::vec h(n-1), p(n-1);

    for(int i = 0; i < n-1; i++) {
        h[i] = x[i+1] - x[i];
        assert(h[i] > 0);
        p[i] = (y[i+1] - y[i]) / h[i];
    }

    c[0] = 0;

    for(int i = 0; i < n-2; i++)
        c[i+1] = (p[i+1] - p[i] - c[i]*h[i]) / h[i+1];

    c[n-2] /= 2;

    for(int i = n-3; i >= 0; i--)
        c[i] = (p[i+1] - p[i] - c[i+1]*h[i+1]) / h[i];

    for(int i = 0; i < n-1; i++)
        b[i] = p[i] - c[i]*h[i];
}

int qspline::binsearch(double z) const {
    assert(z >= x[0] && z <= x[n-1]);

    int i = 0;
    int j = n - 1;

    while(j - i > 1) {
        int mid = (i + j)/2;

        if(z > x[mid]) i = mid;
        else j = mid;
    }

    return i;
}

double qspline::eval(double z) const {
    int i = binsearch(z);
    double dx = z - x[i];
    return y[i] + b[i]*dx + c[i]*dx*dx;
}

double qspline::deriv(double z) const {
    int i = binsearch(z);
    double dx = z - x[i];
    return b[i] + 2*c[i]*dx;
}

double qspline::integ(double z) const {
    int i = binsearch(z);
    double sum = 0;

    for(int j = 0; j < i; j++) {
        double dx = x[j+1] - x[j];
        sum += y[j]*dx + b[j]*dx*dx/2 + c[j]*dx*dx*dx/3;
    }

    double dx = z - x[i];
    sum += y[i]*dx + b[i]*dx*dx/2 + c[i]*dx*dx*dx/3;

    return sum;
}