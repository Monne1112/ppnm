#include <iostream>
#include <random>
#include "evd.h"
#include "matrix.h"

int main() {
    int n = 5;
    pp::mat A(n,n);

    std::mt19937 gen(1);
    std::uniform_real_distribution<double> dist(-5,5);

    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            double x = dist(gen);
            A(i,j)=x;
            A(j,i)=x;
        }
    }

    pp::EVD evd(A);
    std::cout << "A:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            std::cout << A(i,j) << " ";
        std::cout << "\n";
    }

    std::cout << "Eigenvalues:\n";
    for(int i=0;i<n;i++)
        std::cout << evd.w[i] << "\n";

    pp::mat D = pp::transpose(evd.V) * A * evd.V;
    pp::mat I = pp::transpose(evd.V) * evd.V;

    std::cout << "\nV^T * A * V = D:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            std::cout << D(i,j) << " ";
        std::cout << "\n";
    }

    std::cout << "\nV^T * V = I:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            std::cout << I(i,j) << " ";
        std::cout << "\n";
    }
    std::cout << "\nV * V^t = I:\n";
    pp::mat I2 = evd.V * pp::transpose(evd.V);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)            std::cout << I2(i,j) << " ";
        std::cout << "\n";
    }
    std::cout << "\nV * D * V^T = A:\n";
    pp::mat A2 = evd.V * D * pp::transpose(evd.V);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)            std::cout << A2(i,j) << " ";
        std::cout << "\n";
    }


    return 0;
}