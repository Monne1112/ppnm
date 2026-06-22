#include "recover.h"
#include "qr.h"
#include "matrix.h"
#include <cmath>


pp::vec recover(const pp::vec& y) {
    pp::vec z(0); 
    for (int i = 0;i < y.size(); i++){
        if (y[i] == 0) {
            z.push_back(i);
        }
    }
    return z;
    
}