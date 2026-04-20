#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>


double erf(double x) {
    if (x<0) return -erf(-x);
    std::vector<double> a = {0.254829592, -0.284496736, 1.421413741, -1.453152027, 1.061405429};
    double t=1/(1+0.3275911*x);
    double sum=t*(a[0]+t*(a[1]+t*(a[2]+t*(a[3]+t*a[4]))));/* the right thing */
    return 1-sum*std::exp(-x*x);
}

double sgamma(double x){
	if(x<0)return std::numbers::pi/std::sin(std::numbers::pi*x)/sgamma(1-x);
	if(x<9)return sgamma(x+1)/x;
	double lnsgamma=std::log(2*std::numbers::pi)/2
	+(x-0.5)*std::log(x)
	-x
	+(1.0/12)/x
	-(1.0/360)/(x*x*x)
	+(1.0/1260)/(x*x*x*x*x);
	return std::exp(lnsgamma);
}

double lngamma(double x){
if(x<=0) return NAN;
if(x<9) return lngamma(x+1)-std::log(x);
return x*std::log(x+1/(12*x-1/x/10))-x+std::log(2*std::numbers::pi/x)/2;
}


int main(int argc,char** argv){
	double xmin=0,xmax=10,dx=0.125;
	for(int i=0;i<argc;i++){
		std::string arg=argv[i];
		std::cerr<<"i= "<<i<<" arg="<<arg<<"\n";
		if(arg=="-xmin" && i+1<argc)xmin=std::stod(argv[i+1]);
		if(arg=="-xmax" && i+1<argc)xmax=std::stod(argv[i+1]);
		if(arg=="-dx" && i+1<argc)dx=std::stod(argv[i+1]);
		}
	std::cerr << "xmin= " << xmin << "\n";
    std::cerr << "xmax= " << xmax << "\n";
    std::cerr << "dx= " << dx << "\n";
    std::cout << std::scientific;
    std::cout << "# x erf(x) gamma(x) lngamma(x)\n";

    for (double x = xmin; x <= xmax; x += dx) {
        // skip poles of gamma at 0, -1, -2, ...
        if (std::abs(x - std::round(x)) < 1e-10 && x <= 0) continue;

        std::cout << x << " " << erf(x) << " " << sgamma(x) << " " << lngamma(x) << "\n";
	}


	return 0;
}