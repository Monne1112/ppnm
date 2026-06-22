#include "recover.h"
#include "qr.h"
#include "matrix.h"
#include <cstdlib>
#include <cmath>


pp::vec recover(const pp::vec& y) {
    int N = y.size();

    std::vector<int> missing;

    for (int i = 0;i < N; i++){
        if (y[i] == 0) 
            missing.push_back(i);
        }
    int m = missing.size();
    if (m == 0) return y;


    pp::mat A(N-2, m);
    pp::vec b(N-2);

    for (int row = 0; row < N-2; row++){
        int ids[3] = {row, row+1, row+2};
        double coeffs[3] = {1,-2,1};

        b[row] = 0;
        
        for (int k = 0; k < 3; k++){
            int idx = ids[k];
            double c = coeffs[k];

            bool is_missing = false;
            int col = -1;

            for (int j = 0; j < m; j++) {
                if(missing[j] == idx) {
                    is_missing = true;
                    col = j;
                    break;
                }
            }
            if (is_missing) {
                A(row, col) += c;
            } else {
                b[row] -= c*y[idx];
            }
        }
    }
    pp::qr decomp(A);
    pp::vec z = decomp.solve(b);

    pp::vec x = y;

    for (int j = 0; j < m; j++){
        int idx = missing[j];
        x[idx] = z[j];
    }

    return x;

    
}