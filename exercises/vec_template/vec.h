#pragma once
#include <iostream>
#include <string>
#include<cstdio>
#include<cmath>
namespace pp {
template<typename T>
struct vec {
    T x, y, z;

    // constructors
    vec(T x, T y, T z) : x(x), y(y), z(z) {}  // parameterized
    vec() : vec(0, 0, 0) {}                                    // default
    vec(const vec&) = default;                                 // copy
    vec(vec&&) = default;                                      // move
    ~vec() = default;                                          // destructor

    // assignment
    vec& operator=(const vec&) = default;                     // copy assignment
    vec& operator=(vec&&) = default;                          // move assignment

    // arithmetic
    vec& operator+=(const vec& other){
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
    vec& operator-=(const vec& other){
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }
    vec& operator*=(double scalar){
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;   
    }
    vec& operator/=(double scalar){
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;   
    }

    // utility
    void set(double a, double b, double c) { x = a; y = b; z = c; }
    void print(const std::string& s = "") const;              // for debugging

    // stream output
    //friend std::ostream& operator<<(std::ostream&, const vec&);
};

template<typename T>
vec<T> operator+(const vec<T>& a, const vec<T>& b){
    return vec<T>(a.x + b.x, a.y + b.y, a.z + b.z);
}
template<typename T>
vec<T> operator-(const vec<T>& a, const vec<T>& b){
    return vec<T>(a.x - b.x, a.y - b.y, a.z - b.z);
}
template<typename T>
vec<T> operator*(const vec<T>& v, double scalar){
    return vec<T>(v.x * scalar, v.y * scalar, v.z * scalar);   
}
template<typename T>
vec<T> operator/(const vec<T>& v, double scalar){
    return vec<T>(v.x / scalar, v.y / scalar, v.z / scalar);   
}
template<typename T>
double dot(const vec<T>& a, const vec<T>& b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
template<typename T>
vec<T> cross(const vec<T>& a, const vec<T>& b){
    return vec<T>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
template<typename T>
double norm(const vec<T>& v){
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
template<typename T>
std::ostream& operator<<(std::ostream& os, const vec<T>& v){
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;  
}
template<typename T>
bool approx(const vec<T>& a, const vec<T>& b, double acc = 1e-6, double eps = 1e-6);

template<typename T>
bool approx(const vec<T>& a, const vec<T>& b, double acc, double eps){
    if(!approx(a.x, b.x, acc, eps)) return false;
    if(!approx(a.y, b.y, acc, eps)) return false;
    if(!approx(a.z, b.z, acc, eps)) return false;
    return true;
}
}