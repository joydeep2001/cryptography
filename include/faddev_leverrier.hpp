#pragma once

#include <cstdint>   
#include "Matrix.hpp"

/**
 * @brief Finds the matrix inverse using faddev laverrier algorithm
 */
template <typename T>
class FaddevLaverrier
{
private:
    Matrix<T> A;           
    uint8_t n;            
    Matrix<T> AInverse;   

public:
    
    FaddevLaverrier(Matrix<T> M);

    Matrix<T> findInverse();
};

