#include <iostream>
#include <cmath>
#include <string>
#include "matrix.h"
#include "evd.h"

int main(int argc, char** argv) {
    double rmax = 10.0;
    double dr = 0.3;
    std::string mode = "normal";

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "-rmax" && i+1 < argc)
            rmax = std::stod(argv[++i]);
        else if (arg == "-dr" && i+1 < argc)
            dr = std::stod(argv[++i]);
        else if (arg == "-mode" && i+1 < argc)
            mode = argv[++i];
    }

    int npoints = int(rmax/dr) - 1;

    pp::vec r(npoints);
    for (int i = 0; i < npoints; i++)
        r[i] = dr * (i+1);

    pp::mat H(npoints, npoints);

    for (int i = 0; i < npoints; i++) {
        H(i,i) = 1.0/(dr*dr) - 1.0/r[i];

        if (i < npoints-1) {
            H(i,i+1) = -0.5/(dr*dr);
            H(i+1,i) = -0.5/(dr*dr);
        }
    }

    pp::EVD evd(H);

    if(mode == "energy") {
        std::cout << dr << " " << rmax << " " << evd.w[0] << "\n";
        return 0;
    }

    if(mode == "wave") {
        double C = 1.0/std::sqrt(dr);

        for(int i = 0; i < npoints; i++) {
            double exact = 2*r[i]*std::exp(-r[i]);
            double num = C*evd.V(i,0);

            if(num < 0) num = -num;

            std::cout << r[i] << " " << num << " " << exact << "\n";
        }

        return 0;
    }

    std::cout << "# rmax = " << rmax << ", dr = " << dr << "\n";
    std::cout << "# lowest eigenvalues:\n";

    for (int k = 0; k < 5; k++)
        std::cout << k << " " << evd.w[k] << "\n";

    return 0;
}