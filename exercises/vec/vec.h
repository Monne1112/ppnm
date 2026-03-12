#pragma once
#include <iostream>
#include <string>
#include<cstdio>
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
    vec& vec::operator+=(const vec& other){
        SELF.x += other.x;
        SELF.y += other.y;
        SELF.z += other.z;
        return SELF;
    }
    vec& vec::operator-=(const vec& other){
        SELF.x -= other.x;
        SELF.y -= other.y;
        SELF.z -= other.z;
        return SELF;
    }
    vec& vec::operator*=(double scalar){
        SELF.x *= scalar;
        SELF.y *= scalar;
        SELF.z *= scalar;
        return SELF;   
    }
    vec& vec::operator/=(double scalar){
        SELF.x /= scalar;
        SELF.y /= scalar;
        SELF.z /= scalar;
        return SELF;   
    }

    // utility
    void set(double a, double b, double c) { x = a; y = b; z = c; }
    void print(const std::string& s = "") const;              // for debugging

    // stream output
    friend std::ostream& operator<<(std::ostream&, const vec&);
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



// approximate equality
bool approx(const vec&, const vec&, double acc = 1e-6, double eps = 1e-6);

}