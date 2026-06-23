#include "qr.h"
#include "recover.h"
#include <fstream>
#include <iostream>
#include <random>
#include <cmath>



int main (){
    srand(1);
    int N = 50;
    pp::vec original(N);
    pp::vec corrupted(N);

    for(int i=0;i<N;i++)
        original[i] = std::sin(0.1*i)*std::cos(std::pow(0.1*i, 2));

    corrupted = original;

    for(int i=0;i<N;i++)
        if(rand()%2==0)
            corrupted[i] = 0;

    pp::vec recovered = recover(corrupted);

    pp::vec error = (recovered-original)/original;



    std::ofstream out("recover.data");
    for (int i = 0; i < N; i++){
        out << i << " "
            << original[i] << " "
            << corrupted[i] << " "
            << recovered[i] << " "
            << error[i] << "\n";
    }

    return 0;
}