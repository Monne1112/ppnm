#pragma once
#include <iostream>
#include <cmath>

inline void print_row(std::ostream& out, double x) {
    out << x << " " << std::sin(x) << " " << std::cos(x) << "\n";
}

template <typename InStream>
inline void process_stream(InStream& in, std::ostream& out) {
    double x;
    while (in >> x) {
        print_row(out, x);
    }
}