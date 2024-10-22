#include <iostream>
#include <bits/stdc++.h>
#include "../include/Matrix.hpp"

using namespace std;

/**
 * @brief Extracts co-efficients from the polynomial
 * @param term List of terms present in the polynomial
 * @return An integer where each bit represent the co-efficients
 */
template <typename T>
T createPoly(vector<int> &terms)
{
    T poly = 0;

    for (auto term : terms)
    {
        poly |= (1 << term);
    }

    return poly;
}

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

int main()
{
    // x^32 + x^22 + x^21 + x^20 + x^18 + x^17 + x^15 + x^13 + x^12 + x^10 + x^8 + x^6 + x^4 + x^1 + 1
    vector<int> terms = {32, 22, 21, 20, 18, 17, 15, 13, 12, 10, 8, 6, 4, 1, 0};
    uint32_t mask = createPoly<uint32_t>(terms);

    cout << setw(8) << setfill('0') << hex << mask << " ";

    cout << endl;

    Matrix<uint32_t> M(mask);

    M.debugPrint();

    FaddevLaverrier<uint32_t> fl(M);

    Matrix<uint32_t> MInverse = fl.findInverse();

    MInverse.debugPrint();
}