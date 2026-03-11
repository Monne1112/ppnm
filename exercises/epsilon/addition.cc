#include <iostream>
#include <limits>
#include <cmath>
#include "iomanip"


void addition() {
    double epsilon = std::pow(2.0, -52); // machine epsilon for double precision
    double tiny = epsilon / 2.0;
    double a = 1 + tiny + tiny;
    double b = tiny + tiny + 1;
    double c = 1 + 2 * tiny;
    std::cout << "Cummutativity test for addition:\n";
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "c: " << c << "\n";
    std::cout << "a == b: " << (a==b ? "true":"false") << "\n";
    std::cout << "a == c: " << (a==c ? "true":"false") << "\n";
    std::cout << "b == c: " << (b==c ? "true":"false") << "\n";

    std::cout << std::fixed << std::setprecision(17);
    std::cout << "       tiny=" << tiny << "\n";
    std::cout << "1+tiny+tiny=" << a << "\n";
    std::cout << "tiny+tiny+1=" << b << "\n";
} 