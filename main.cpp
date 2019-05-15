/**
 * @file main.cpp
 * @author Giles Carlos
 * @brief Test BigNumbers.
 *
 */

#include <gtest/gtest.h>
#include "BigNumbersLib.h"

class BigNumbersTest : public testing::Test {
    
};

TEST_F(BigNumbersTest, CanAdd) {
    BigNum::BigNumbers x("10000000001");
    BigNum::BigNumbers y("999999999");
    
    BigNum::BigNumbers real = x + y;
    
    BigNum::BigNumbers expected("11000000000");
    
    ASSERT_TRUE((expected == real));
}

TEST_F(BigNumbersTest, CanSubtract) {
    BigNum::BigNumbers x("80000000000");
    BigNum::BigNumbers y("55600000");
    
    BigNum::BigNumbers real = x - y;
    
    BigNum::BigNumbers expected("79944400000");
    
    ASSERT_TRUE((expected == real));
}

