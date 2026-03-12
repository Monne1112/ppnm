#include <iostream>
#include "vec.h"

int main() {
    pp::vec<double> a(1, 2, 3);
    pp::vec<double> b(4, 5, 6);

    auto c = a + b;
    std::cout << c << '\n';

    return 0;
}