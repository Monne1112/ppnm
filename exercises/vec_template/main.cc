#include <iostream>
#include "vec.h"

int main() {
    pp::vec<float> a(1, 2, 3);
    pp::vec<float> b(4, 5, 6);

    auto c = a + b;
    std::cout << c << '\n';

    return 0;
}