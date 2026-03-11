#include<iostream>
#include<limits>
void epsilon(){
    float f = 1.0f; while (1.0f + f != 1.0f) f /= 2.0f;
    double d = 1.0; while (1.0 + d != 1.0) d /= 2.0;
    long double ld = 1.0L; while (1.0L + ld != 1.0L) ld /= 2.0;
    std::cout << "Calculated machine epsilon:\n";
    std::cout << "float epsilon: " << f << "\n";
    std::cout << "double epsilon: " << d << "\n";
    std::cout << "long double epsilon: " << ld << "\n";
    std::cout << "float epsilon from limits: " << std::numeric_limits<float>::epsilon() << "\n";
    std::cout << "double epsilon from limits: " << std::numeric_limits<double>::epsilon() << "\n";
    std::cout << "long double epsilon from limits: " << std::numeric_limits<long double>::epsilon() << "\n";
}