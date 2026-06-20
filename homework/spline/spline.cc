#include "spline.h"
#include "matrix.h"
#include <cassert>

int binsearch(const pp::vec& x, double z) {
    assert(z >= x[0] && z <= x[x.size() - 1]);

    int i = 0;
    int j = x.size() - 1;

    while(j - i > 1) {
        int mid = (i + j)/2;

        if(z > x[mid]) i = mid;
        else j = mid;
    }

    return i;
}

double linterp(const pp::vec& x,
               const pp::vec& y,
               double z) {
    int i = binsearch(x,z);

    double dx = x[i+1] - x[i];
    double dy = y[i+1] - y[i];

    assert(dx > 0);

    return y[i] + dy/dx * (z - x[i]);
}

double linterpInteg(const pp::vec& x,
                    const pp::vec& y,
                    double z) {
    int iz = binsearch(x,z);
    double sum = 0;

    for(int i = 0; i < iz; i++) {
        double dx = x[i+1] - x[i];
        sum += 0.5 * (y[i] + y[i+1]) * dx;
    }

    double dx = z - x[iz];
    double slope = (y[iz+1] - y[iz]) / (x[iz+1] - x[iz]);
    double yz = y[iz] + slope * dx;

    sum += 0.5 * (y[iz] + yz) * dx;

    return sum;
}