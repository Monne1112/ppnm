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

    void push_back(double x) {
        data.push_back(x);
    }
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
inline mat transpose(const mat& A) {
    mat B(A.cols(), A.rows());

    for (int i = 0; i < A.rows(); i++)
        for (int j = 0; j < A.cols(); j++)
            B(j,i) = A(i,j);

    return B;
}

inline vec operator*(const mat& A, const vec& x) {
    assert(A.cols() == x.size());

    vec y(A.rows());

    for (int i = 0; i < A.rows(); i++) {
        y[i] = 0;
        for (int j = 0; j < A.cols(); j++)
            y[i] += A(i,j) * x[j];
    }

    return y;
}

inline mat operator*(const mat& A, const mat& B) {
    assert(A.cols() == B.rows());

    mat C(A.rows(), B.cols());

    for (int i = 0; i < A.rows(); i++)
        for (int j = 0; j < B.cols(); j++) {
            C(i,j) = 0;
            for (int k = 0; k < A.cols(); k++)
                C(i,j) += A(i,k) * B(k,j);
        }

    return C;
}

inline vec operator+(const vec& a, const vec& b) {
    assert(a.size() == b.size());
    vec c(a.size());
    for(int i=0;i<a.size();i++) c[i]=a[i]+b[i];
    return c;
}

inline vec operator-(const vec& a, const vec& b) {
    assert(a.size() == b.size());
    vec c(a.size());
    for(int i=0;i<a.size();i++) c[i]=a[i]-b[i];
    return c;
}

inline vec operator*(const vec& v, double a) {
    vec u(v.size());
    for(int i=0;i<v.size();i++) u[i]=v[i]*a;
    return u;
}

inline vec operator*(double a, const vec& v) {
    return v*a;
}
}