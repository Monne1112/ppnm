#include<cmath>
#include<complex>
#include<iostream>
#include"sfuns.h"
using complex = std::complex<double>;
constexpr double pi = 3.14159265358979324;
constexpr double E = 2.71828182845904523;
constexpr complex I = complex(0,1);
namespace	sfuns{
void sfuns() {
	std::cout << "Sqrt(2): " << std::sqrt(2) << "\n"; 
	std::cout << "2^(1/5): " << std::pow(2,0.2) << "\n";
	std::cout << "E^(pi): " << std::pow(E, pi) << "\n";
	std::cout << "E^(i): " << std::pow(E, I) << "\n";
	std::cout << "pi^(E): " << std::pow(pi, E) << "\n";
	std::cout << "pi^(i): " << std::pow(pi, I) << "\n";
	std::cout << "E^(i): " << std::pow(E, I) << "\n";
	std::cout << "i^i: " << std::pow(I, I) << "\n";
	std::cout << "log(i): " << std::log(I) << "\n";
}

}
