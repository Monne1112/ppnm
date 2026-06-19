#include "evd.h"
#include "matrix.h"
#include <cmath>

namespace pp {

    void EVD::timesJ(mat& A, int p, int q, double theta) {
        double c = std::cos(theta), s = std::sin(theta);
        for (int i = 0; i < A.rows(); i++) {
            double aip = A(i,p), aiq = A(i,q);
            A(i,p) = c*aip - s*aiq;
            A(i,q) = s*aip + c*aiq;
        }
    }
    void EVD::Jtimes(mat& A, int p, int q, double theta) {
        double c = std::cos(theta), s = std::sin(theta);
        for (int j = 0; j < A.cols(); j++) {
            double apj = A(p,j), aqj = A(q,j);
            A(p,j) =  c*apj + s*aqj;
            A(q,j) = -s*apj + c*aqj;
        }
    }
    EVD::EVD(mat A) : w(A.rows()), V(A.rows(), A.rows()) {
        int n = A.rows();
        V = pp::mat::identity(n);

        bool changed;
        do {
            changed = false;
            for (int p = 0; p < n-1; p++) {
                for (int q = p+1; q < n; q++) {
                    double app = A(p,p);
                    double aqq = A(q,q);
                    double apq = A(p,q);

                    double theta = 0.5 * std::atan2(2*apq, aqq-app);

                    double c = std::cos(theta);
                    double s = std::sin(theta);

                    double new_app = c*c*app - 2*s*c*apq + s*s*aqq;
                    double new_aqq = s*s*app + 2*s*c*apq + c*c*aqq;

                    if (new_app != app || new_aqq != aqq) {
                        changed = true;
                        timesJ(A, p, q, theta);
                        Jtimes(A, p, q, -theta);
                        timesJ(V, p, q, theta);
                    }
                }
            }
        } while (changed);

        for (int i = 0; i < n; i++) {
            w[i] = A(i,i);
        }
    }
} 