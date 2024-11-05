#include <gtest/gtest.h>
#include <cstdint>
#include <vector>
#include "../include/Utils.hpp"

using namespace std;


TEST(CharPolyMask, CreateCharPolyMask) 
{
    //x^8 + x^4 + x^3 + x^2 + 1
    vector<int> terms = {8, 4, 3, 2, 0};
    uint8_t mask = createPoly<uint8_t>(terms);
    EXPECT_EQ(mask, 0b00011101);
} 

TEST(Popcount, PopcountTest)
{
    EXPECT_EQ(popcount<uint8_t>(8), 1);
    EXPECT_EQ(popcount<uint8_t>(9), 2);
    EXPECT_EQ(popcount<uint8_t>(255), 8);
}