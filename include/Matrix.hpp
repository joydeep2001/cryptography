#include <vector>

#pragma once

using namespace std;

/**
 * @brief This class provides a implementation of a binary Matrix.
 * A Binary matrix contains only 0s and 1s as it's element. As we
 * have only 0 and 1 as the value of the matrix we can optimize the
 * space by store a row inside a variable. This matrix currenly supprts
 * 8, 16, 32 & 64 bit squre matrix
 */
template <typename T>
class Matrix
{
    vector<T> M;

public:
    Matrix();

    Matrix(const Matrix<T> &A);

    /**
     * @brief This constructor can be used to create a square matrix of size n x n.
     * @param n Dimesion of the matrix (n x n)
     * @param isIdentity If 1 is passed then an Identity matrix of n x n is created,
     * otherwise a n x n matrix created with all elements as 0.
     */
    Matrix(int n, bool isIdentity);

    /**
     * @brief This constructor can be used to create a companion matrix of given polynomial.
     * @param poly is the coeeficients of the polynomial
     */
    Matrix(T poly);

    Matrix(vector<T>& X);

    vector<T> get();

    unsigned int size();

    int getTrace();

    Matrix<T> getTranspose();

    Matrix<T> operator*(T d);

    Matrix<T> operator*(Matrix<T> &B);

    Matrix<T> operator^(Matrix<T> &X);

    Matrix<T> &operator=(const Matrix<T> &X);

    T &operator[](int index);

    /**
     * @brief Prints the binary matrix for debug purposes
     */
    void debugPrint();
};