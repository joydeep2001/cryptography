#include <iostream>
#include <bits/stdc++.h>
#include "../include/Matrix.hpp"
#include "../include/Utils.hpp"
#include "../include/faddev_leverrier.hpp"

using namespace std;

template <typename T>
FaddevLaverrier<T>::FaddevLaverrier(Matrix<T> M)
{
    A = M;
    n = M.size();
}

template <typename T>
Matrix<T> FaddevLaverrier<T>::findInverse()
{
    Matrix<T> B = A;
    Matrix<T> I(n, 1);

    for (int i = 0; i < n; i++)
    {
        int d = B.getTrace();  
        cout << "Trace" << i << ": " << d << endl;
        Matrix<T> dI = I * d;  
        Matrix<T> D = B ^ dI;   
        B = A * D;   
        cout << "D" << i;         
        D.debugPrint();
        cout << "B" << i + 1;  
        B.debugPrint();
        if (i == n - 2)
        {
            AInverse = D;      
        }
    }

    return AInverse; 
}

template class FaddevLaverrier<uint8_t>;
template class FaddevLaverrier<uint16_t>;
template class FaddevLaverrier<uint32_t>;
template class FaddevLaverrier<uint64_t>;