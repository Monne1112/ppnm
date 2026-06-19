#include<cmath>
#include<iostream>
#include<vector>
#include<random>
#include "matrix.h"
#include "qr.h"



int main() {
    int n = 5, m = 5;
    pp::mat A(n, m);

    std::mt19937 gen(1);
    std::uniform_real_distribution<double> dist(-5, 5);

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            A(i, j) = dist(gen);
    pp::vec b(n);

    for (int i = 0; i < n; i++)
        b[i] = dist(gen);
    pp::qr decomp(A);

    std::cout << "QR decomposition done\n";
    std::cout << "A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << A(i, j) << " ";
        std::cout << "\n";
    }
    std::cout << "Q:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << decomp.Q(i, j) << " ";
        std::cout << "\n"; 
    }
    std::cout << "R:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            std::cout << decomp.R(i, j) << " ";
        std::cout << "\n"; 
    }
    std::cout << "Q^T * Q:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            std::cout << pp::dot(decomp.Q.col(i), decomp.Q.col(j)) << " ";
        std::cout << "\n"; 
    }
    std::cout << "QR = A CHECK (1e-10):\n";
    double maxdiff = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double sum = 0;

            for (int k = 0; k < m; k++)
                sum += decomp.Q(i, k) * decomp.R(k, j);

            double diff = std::abs(sum - A(i, j));

            if (diff > maxdiff)
                maxdiff = diff;
        }
    }

    std::cout << "max |QR - A| = " << maxdiff << "\n";

    if (maxdiff < 1e-10)
        std::cout << "QR = A check (1e-10) PASSED\n";
    else
        std::cout << "QR = A check (1e-10) FAILED\n";
    
    std::cout << "Solving Ax = b\n";
    pp::vec x = decomp.solve(b);
    double maxres = 0;

    for (int i = 0; i < n; i++) {
        double Axi = 0;

        for (int j = 0; j < m; j++)
            Axi += A(i,j) * x[j];

        double res = std::abs(Axi - b[i]);

        if (res > maxres)
            maxres = res;
    }

    std::cout << "|Ax-b| = " << maxres << "\n";
    std::cout << "Det(R) = " << decomp.det() << "\n";

    
}