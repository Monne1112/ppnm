#include<cmath>
#include<iostream>
#include<numbers>
#include"sfuns.h"

int main () {
    sfuns::sfuns();
    for (int i = 0; i < 10; ++i) {
        std::cout << "gamma(" << i << "): " << sfuns::fgamma(i) << "\n";
    }
    return 0;
}
