#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

namespace pp {

struct vec {
    std::vector<double> data;

    vec() {}
    vec(int n) : data(n) {}
    vec(double x, double y, double z) : data({x, y, z}) {}

    int size() const { return data.size(); }

    double& operator[](int i) { return data[i]; }
    double operator[](int i) const { return data[i]; }
};

inline double dot(const vec& a, const vec& b) {
    assert(a.size() == b.size());
    double sum = 0;
    for (int i = 0; i < a.size(); ++i)
        sum += a[i] * b[i];
    return sum;
}

inline double norm(const vec& v) {
    return std::sqrt(dot(v, v));
}

struct mat {
    std::vector<vec> columns;

    mat() {}
    mat(int n, int m) : columns(m, vec(n)) {}

    int rows() const { return columns[0].size(); }
    int cols() const { return columns.size(); }

    double& operator()(int i, int j) {
        return columns[j][i];
    }

    double operator()(int i, int j) const {
        return columns[j][i];
    }

    vec& col(int j) {
        return columns[j];
    }

    const vec& col(int j) const {
        return columns[j];
    }

    static mat identity(int n) {
        mat I(n, n);
        for (int i = 0; i < n; ++i)
            I(i, i) = 1;
        return I;
    }
};

}