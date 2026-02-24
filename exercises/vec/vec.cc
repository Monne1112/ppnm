#include<iostream>
#include"vec.h" 
#include<cmath>
#define SELF (*this)
namespace pp { 
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
    vec operator+(const vec& a, const vec& b){
        return vec(a.x + b.x, a.y + b.y, a.z + b.z);
    }
    vec operator-(const vec& a, const vec& b){
        return vec(a.x - b.x, a.y - b.y, a.z - b.z);
    }
    vec operator*(const vec& v, double scalar){
        return vec(v.x * scalar, v.y * scalar, v.z * scalar);   
    }
    vec operator/(const vec& v, double scalar){
        return vec(v.x / scalar, v.y / scalar, v.z / scalar);   
    }
    double dot(const vec& a, const vec& b){
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }
    vec cross(const vec& a, const vec& b){
        return vec(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
    }
    double norm(const vec& v){
        return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }
    bool approx(const vec& a, const vec& b, double acc, double){
        return (std::abs(a.x - b.x) < acc) && (std::abs(a.y - b.y) < acc) && (std::abs(a.z - b.z) < acc);
    }
    std::ostream& operator<<(std::ostream& os, const vec& v){
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;  
    }
    
}