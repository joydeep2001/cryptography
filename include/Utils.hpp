#pragma once
#include<vector>

using namespace std;
/**
 * @brief Counts the number of set bits in the polynomial
 * @param n Unsinged integer number
 * @return Number of set bits
 */
template <typename T>
int popcount(T n);

/**
 * @brief Extracts co-efficients from the polynomial
 * @param term List of terms present in the polynomial
 * @return An integer where each bit represent the co-efficients
 */
template <typename T>
T createPoly(vector<int> &terms);