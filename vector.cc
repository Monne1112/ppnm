#include<iostream>
#include<cstdio>
#include<vector>
#include"hello.h"
int main(){
	hello();
	double a = 1.0;
	double b = a;
	if(a == b) std::cout << "a==b\n";
	else std ::cout << "a!=b";	
	std::vector<double> v {1,2,3};
	auto u = v;
	auto& w = v;
return 0;}
