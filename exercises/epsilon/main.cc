#include<iostream>

void epsilon ();
void addition ();
bool approx(double a, double b, double acc=1e-9, double eps=1e-9);

int main(){
    epsilon();
    addition();
    double d1 = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
    double d2 = 0.1*8;
    std::cout << "Comparing d1 and d2:\n";
    std::cout << "d1: 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 \n";
    std::cout << "d2: 0.1 * 8\n";
    std::cout << (approx(d1, d2) ? "true" : "false") << "\n";
}