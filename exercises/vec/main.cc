#include <iostream>
#include "vec.h"

int main() {
    pp::vec a(1,2,3);
    pp::vec b(4,5,6);
    pp::vec c = a + b;
    std::cout << c << '\n';
    return 0;
}