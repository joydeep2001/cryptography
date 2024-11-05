#include <gtest/gtest.h>
#include <cstdint>
#include <algorithm>
#include "../include/faddev_leverrier.hpp"
#include "../include/Matrix.hpp"

using namespace std;

TEST(FaddevLaverrierTest, Constructor)
{

    vector<uint8_t> v1 = {0b00000001,
                          0b10000000,
                          0b01000001,
                          0b00100001,
                          0b00010001,
                          0b00001000,
                          0b00000100,
                          0b00000010};

    
    

    Matrix<uint8_t>
        input(v1);
    FaddevLaverrier<uint8_t> fl(input);

    Matrix<uint8_t> output = fl.findInverse();
    output.debugPrint();
    // vector<uint8_t>v2 = {
    //     0b01000000,
    //     0b10100000,
    //     0b10010000,
    //     0b10001000,
    //     0b00000100,
    //     0b00000010,
    //     0b00000001,
    //     0b10000000,
    // };
    
    //Matrix<uint8_t> output(v2);

    Matrix<uint8_t> shouldBeIdentity = (output * input);
    shouldBeIdentity.debugPrint();

    vector<uint8_t> outputVec = shouldBeIdentity.get();

    vector<uint8_t> identity_8x8 = {
        0b10000000,
        0b01000000,
        0b00100000,
        0b00010000,
        0b00001000,
        0b00000100,
        0b00000010,
        0b00000001,
    };

    EXPECT_TRUE(equal(outputVec.begin(), outputVec.end(), identity_8x8.begin()));
}
