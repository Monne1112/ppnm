#include<iostream>
#include"vec.h" 
#include<cmath>
#define SELF (*this)
namespace pp { 

    bool approx(const vec& a, const vec& b, double acc, double eps){
        return (std::abs(a.x - b.x) < acc) && (std::abs(a.y - b.y) < acc) && (std::abs(a.z - b.z) < acc);
        double max_ab = std::max(std::abs(a.x), std::abs(b.x));
        return (diff <= eps * max_ab);
    }
}