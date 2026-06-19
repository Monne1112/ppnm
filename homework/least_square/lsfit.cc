#include "lsfit.h"
#include "qr.h"
#include "matrix.h"
#include <tuple>

std::tuple<pp::vec, pp::mat> lsfit(
    const std::vector<std::function<double(double)>>& fs,
    const pp::vec& x,
    const pp::vec& y,
    const pp::vec& dy
) {
    int n = x.size();
    int m = fs.size();

    pp::mat A(n, m);
    pp::vec b(n);

    for (int i = 0; i < n; i++) {
        b[i] = y[i] / dy[i];

        for (int k = 0; k < m; k++)
            A(i,k) = fs[k](x[i]) / dy[i];
    }

    pp::qr decomp(A);
    pp::vec c = decomp.solve(b);
    pp::mat Rinv = decomp.Rinverse();
    pp::mat I = decomp.R * decomp.Rinverse();
    
    std::cout << "R * R^-1:\n";
        for(int i=0;i<I.rows();i++) {
            for(int j=0;j<I.cols();j++)
                std::cout << I(i,j) << " ";
            std::cout << "\n";
        }
    pp::mat cov = Rinv * pp::transpose(Rinv);


    return std::tuple(c, cov);
}