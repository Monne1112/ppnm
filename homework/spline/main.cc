#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "spline.h"
#include "qspline.h"

int main() {
    pp::vec x, y;

    for(double xi = 0; xi <= 9; xi += 0.5) {
        x.push_back(xi);
        y.push_back(std::cos(xi));
    }

    std::ofstream points("points.data");
    for(size_t i = 0; i < x.size(); i++)
        points << x[i] << " " << y[i] << "\n";

    std::ofstream linear("linear.data");
    for(double z = x[0]; z <= x[x.size() - 1]; z += 0.05) {
        linear << z << " "
               << linterp(x,y,z) << " "
               << std::cos(z) << " "
               << linterpInteg(x,y,z) << " "
               << std::sin(z) << "\n";
    }

    std::ofstream constant("constant.data");
    for(double z = x[0]; z <= x[x.size() - 1]; z += 0.05) {
        constant << z << " "
                 << y[binsearch(x,z)] << " "
                 << std::cos(z) << "\n";
    }
    
    std::ofstream quadratic("quadratic.data");
    pp::vec qx(5), qy(5);
    for(int i = 0; i<5; i++){
        qx[i]=i+1;
        qy[i] = qx[i]*qx[i];
    }

    qspline s(qx,qy);

    for(double z = 1; z <= 5; z += 0.1) {
        quadratic << z << " "
                << s.eval(z) << " "
                << z*z << " "
                << s.deriv(z) << " "
                << 2*z << " "
                << s.integ(z) << " "
                << (z*z*z - 1)/3.0 << "\n";
    }      
    std::ofstream qcos("qspline_cos.data");
    qspline scos(x,y);

    for(double z = x[0]; z <= x[x.size()-1]; z += 0.05) {
        qcos << z << " "
            << scos.eval(z) << " "
            << std::cos(z) << " "
            << scos.deriv(z) << " "
            << -std::sin(z) << " "
            << scos.integ(z) << " "
            << std::sin(z) << "\n";
    }

    
    return 0;


   

}