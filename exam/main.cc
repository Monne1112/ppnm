#include "qr.h"
#include "recover.h"
#include <fstream>
#include <iostream>
#include <random>
#include <cmath>



int main (){
    srand(1);
    int N = 100;
    pp::vec original(N);
    pp::vec corrupted(N);

    for(int i=0;i<N;i++)
        original[i] = std::sin(0.1*i)*std::cos(0.1*i);

    corrupted = original;

    for(int i=0;i<N;i++)
        if(rand()%2==0)
            corrupted[i] = 0;

    pp::vec recovered = recover(corrupted);

    double error = pp::norm(recovered-original)/pp::norm(original);
    std::cerr << "relative error = " << error << "\n";

    std::ofstream out("recover.data");
    for (int i = 0; i < N; i++){
        out << i << " "
            << original[i] << " "
            << corrupted[i] << " "
            << recovered[i] << "\n";
    }

    return 0;
}