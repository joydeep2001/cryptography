#include <iostream>
#include <vector>
#include "../include/Matrix.hpp"
#include <bitset>
#include "../include/Utils.hpp"

using namespace std;

template <typename T>
Matrix<T>::Matrix() {}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &A) : M(A.M) {}

template <typename T>
Matrix<T>::Matrix(vector<T> &A) : M(A) {}

template <typename T>
Matrix<T>::Matrix(int n, bool isIdentity)
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

template <typename T>
Matrix<T>::Matrix(T poly)
{
    int totalBits = sizeof(T) * 8;

    M.resize(totalBits, 0);

    for (T i = 0; i < totalBits; i++)
    {

        M[i] |= (1 << totalBits - i);
        T bit = (poly >> i) & 1;
        M[i] |= bit;
    }
}

template <typename T>
vector<T> Matrix<T>::get()
{
    return M;
}

template <typename T>
unsigned int Matrix<T>::size()
{
    return M.size();
}

template <typename T>
int Matrix<T>::getTrace()
{
    int t = 0;
    int n = M.size();
    for (int i = n - 1; i >= 0; i--)
    {
        t ^= (M[i] >> i) & 1;
    }

    return t;
}

template <typename T>
Matrix<T> Matrix<T>::getTranspose()
{
    int n = M.size();
    Matrix<T> transpose(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transpose[i] |= (M[j] >> (n - 1 - i) & 1);
            if (j == n - 1)
                continue;
            transpose[i] <<= 1;
        }
    }

    return transpose;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(T d)
{
    if (d == 1)
        return Matrix<T>(*this);

    return Matrix<T>(M.size(), 0);
}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &B)
{

    Matrix<T> BT = B.getTranspose();
    int n = M.size();
    Matrix<T> result(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i] |= (popcount<T>(M[i] & BT[j]) & 1) << (n - 1 - j);
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator^(Matrix<T> &X)
{
    Matrix<T> R(M.size());
    for (int i = 0; i < X.size(); i++)
    {
        R.M[i] = M[i] ^ X.M[i];
    }

    return R;
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &X)
{
    if (this != &X)
    {
        M.assign(X.M.begin(), X.M.end());
    }
    return *this;
}

template <typename T>
T &Matrix<T>::operator[](int index)
{
    return M[index];
}

template <typename T>
void Matrix<T>::debugPrint()
{
    cout << "MATRIX\n";
    for (int i = 0; i < M.size(); i++)
    {
        cout << bitset<sizeof(T) * 8>(M[i]) << endl;
    }
    cout << "\n";
}

template class Matrix<uint8_t>;
template class Matrix<uint16_t>;
template class Matrix<uint32_t>;
template class Matrix<uint64_t>;