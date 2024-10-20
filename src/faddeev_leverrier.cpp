#include <iostream>
#include <bits/stdc++.h>

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
 * @brief This class provides a full implementation of Matrix
 */
template <typename T>
class Matrix
{
    vector<T> M;

public:
    Matrix() {}

    Matrix(const Matrix &A) : M(A.M) {}

    Matrix(int n, bool isIdentity)
    {
        if (!isIdentity)
        {
            M.resize(n, 0);
            return;
        }

        int x = 1 << (n - 1);
        M.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            M[i] = x >> i;
        }
    }

    Matrix(T poly)
    {
        int totalBits = sizeof(T) * 8;

        M.resize(totalBits, 0);

        for (T i = totalBits; i > 0; i--)
        {

            M[i] |= (1 << totalBits);
            T bit = (poly >> (i - 1)) & 1;
            M[i] |= bit;
        }
    }

    int size()
    {
        return M.size();
    }

    int getTrace()
    {
        int t = 0;
        int n = M.size();
        for (int i = n - 1; i >= 0; i--)
        {
            t ^= (M[i] >> i) & 1;
        }

        return t;
    }

    Matrix<T> operator*(T d)
    {
        if (d == 1)
            return Matrix<T>(*this);

        return Matrix<T>(M.size(), 0);
    }

    Matrix<T> operator*(Matrix<T> &B)
    {
        int totalBits = sizeof(T) * 8;
        Matrix<T> result(M.size(), 0);

        for (int i = 0; i < totalBits; ++i)
        {
            T rowResult = 0;
            for (int j = 0; j < totalBits; ++j)
            {

                T bit = (B.M[j] >> (totalBits - 1 - i)) & 1;

                if (bit)
                {
                    rowResult ^= M[j];
                }
            }

            result.M[i] = rowResult;
        }

        return result;
    }

    Matrix<T> operator^(Matrix<T> &X)
    {
        Matrix<T> R(M.size());
        for (int i = 0; i < X.size(); i++)
        {
            R.M[i] = M[i] ^ X.M[i];
        }

        return R;
    }

    Matrix<T> &operator=(const Matrix<T> &X)
    {
        if (this != &X)
        { 
            M.assign(X.M.begin(), X.M.end());
        }
        return *this; 
    }

    void debugPrint()
    {
        for (int i = 0; i < M.size(); i++)
        {
            cout << bitset<32>(M[i]) << endl;
        }
        
    }
};

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

    FaddevLaverrier<uint32_t> fl(M);

    Matrix<uint32_t> MInverse = fl.findInverse();

    MInverse.debugPrint();
}