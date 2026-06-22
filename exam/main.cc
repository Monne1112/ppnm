#include "qr.h"
#include <iostream>
#include <random>
#include <cmath>



int main (){
    srand(1);
    int N = 50;
    pp::vec original(N);
    pp::vec corrupted(N);

    for(int i=0;i<N;i++)
        original[i] = std::sin(0.1*i)+1;

    corrupted = original;

    for(int i=0;i<N;i++)
        if(rand()%5==0)
            corrupted[i] = 0;

    pp::vec recovered = recover(corrupted);
    for (i = 0; i < N; i++){
        out << i << " "
            << original[i] << " "
            << corrupted[i] << " "
            << recovered[i] << "\n";
    }
    return 0;
}