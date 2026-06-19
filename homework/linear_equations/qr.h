#pragma once
#include "matrix.h"

namespace pp {

struct qr {
    mat Q, R;

    qr(const mat& A) {
        int n = A.rows();
        int m = A.cols();

        Q = A;
        R = mat(m, m);

        for (int i = 0; i < m; ++i) {
            R(i, i) = norm(Q.col(i));

            for (int k = 0; k < n; ++k)
                Q(k, i) /= R(i, i);

            for (int j = i + 1; j < m; ++j) {
                R(i, j) = dot(Q.col(i), Q.col(j));

                for (int k = 0; k < n; ++k)
                    Q(k, j) -= Q(k, i) * R(i, j);
            }
        }
    }

    vec solve(const vec& b) const { // Solve Q R x = b
        int m = R.cols();

        vec y(m);

        for (int i = 0; i < m; ++i)
            y[i] = dot(Q.col(i), b);

        vec x(m);

        for (int i = m - 1; i >= 0; --i) {
            double sum = 0;

            for (int j = i + 1; j < m; ++j)
                sum += R(i, j) * x[j];

            x[i] = (y[i] - sum) / R(i, i);
        }

        return x;
    }

    double det() const {
        double d = 1;

        for (int i = 0; i < R.cols(); ++i)
            d *= R(i, i);

        return d;
    }

    mat inverse() const {
        int n = R.cols();
        mat B(n, n);

        for (int i = 0; i < n; ++i) {
            vec e(n);
            e[i] = 1;

            vec x = solve(e);

            for (int j = 0; j < n; ++j)
                B(j, i) = x[j];
        }

        return B;
    }
};

}