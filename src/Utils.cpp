#include<vector>
#include <cstdint>

using namespace std;

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

template <typename T>
int popcount(T n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

template uint8_t createPoly<uint8_t>(vector<int>&);
template uint16_t createPoly<uint16_t>(vector<int>&);
template uint32_t createPoly<uint32_t>(vector<int>&);
template uint64_t createPoly<uint64_t>(vector<int>&);

template int popcount<uint8_t>(uint8_t);
template int popcount<uint16_t>(uint16_t);
template int popcount<uint32_t>(uint32_t);
template int popcount<uint64_t>(uint64_t);