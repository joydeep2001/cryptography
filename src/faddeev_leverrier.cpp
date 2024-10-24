#include <iostream>
#include <bits/stdc++.h>
#include "../include/Matrix.hpp"
#include "../include/Utils.hpp"

using namespace std;



/**
 * @brief Finds the matrix inverse using faddev laverrier algorithm
 */
template <typename T>
class FaddevLaverrier
{
    Matrix<T> A;
    uint8_t n;
    Matrix<T> AInverse;

public:
    FaddevLaverrier(Matrix<T> M)
    {
        A = M;
        n = M.size();
    }

    Matrix<T> findInverse()
    {
        Matrix<T> B(A);
        Matrix<T> I(n, 1);

        for (int i = 0; i < n; i++)
        {
            T d = B.getTrace();

            Matrix<T> DI(I * d);
            Matrix<T> D(B ^ DI);
            B = A * D;

            if (i == n - 1)
            {
                AInverse = D;
            }
        }

        return AInverse;
    }
};
