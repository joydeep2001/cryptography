#include <gtest/gtest.h>
#include <cstdint>
#include <algorithm>
#include "../include/Matrix.hpp"

using namespace std;


TEST(MatrixTest, DefaultConstructor) 
{
    Matrix<uint32_t> mat;
    EXPECT_EQ(mat.size(), 0); 
}


TEST(MatrixTest, CharPolyConstructorTest) 
{
    uint8_t mask = 0b00011101;
    Matrix<uint8_t> input(mask);
    vector<uint8_t> outputShouldBe = {
        0b00000001,
        0b10000000,
        0b01000001,
        0b00100001,
        0b00010001,
        0b00001000,
        0b00000100,
        0b00000010
    };
    input.debugPrint();
    vector<uint8_t> inputV = input.get();
    
    EXPECT_TRUE(equal(inputV.begin(), inputV.end(), outputShouldBe.begin()));

}


TEST(MatrixTest, Transpose) 
{
    vector<uint8_t> v1 = {
        0b10001101, 
        0b10000101,
        0b10001101,
        0b10011101,
        0b10001101,
        0b10101111,
        0b01001101,
        0b10001101,
    };
    
    vector<uint8_t> v2 = {
        0b11111101,
        0b00000010,
        0b00000100,
        0b00010000,
        0b10111111,
        0b11111111,
        0b00000100,
        0b11111111,
    };

    Matrix<uint8_t> mat(v1);
    Matrix<uint8_t> trn = mat.getTranspose();

    //mat.debugPrint();
    //trn.debugPrint();
    
    vector<uint8_t> x = trn.get();

    EXPECT_TRUE(equal(x.begin(), x.end(), v2.begin()));
}

TEST(MatrixTest, MultiplyTwoMatrix) 
{
    vector<uint8_t> v1 = {
        0b10001101, 
        0b10000101,
        0b10001101,
        0b10011101,
        0b10001101,
        0b10101111,
        0b01001101,
        0b10001101,
    };
    vector<uint8_t> v2 = {
        0b10001101, 
        0b10000101,
        0b10001101,
        0b10011101,
        0b10001101,
        0b10101111,
        0b01001101,
        0b10001101,
    };

    vector<uint8_t> v3 = {
        0b00100010,
        0b10101111,
        0b00100010,
        0b10111111,
        0b00100010,
        0b11100010,
        0b00101010,
        0b00100010,
    };

    Matrix<uint8_t> m1(v1);
    Matrix<uint8_t> m2(v2);
    Matrix<uint8_t> m3 = m1 * m2;
    vector<uint8_t> x = m3.get();

    EXPECT_TRUE(equal(x.begin(), x.end(), v3.begin()));

}

TEST(MatrixTest, GetTrace) 
{
    vector<uint8_t> v1 = {
        0b00000100,
        0b00000010,
        0b00000101,
        0b10000110,
        0b01000111,
        0b00100011,
        0b00010001,
        0b00001000,
    };

    Matrix<uint8_t> mat(v1);

    int tr = mat.getTrace();

    EXPECT_EQ(tr, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
