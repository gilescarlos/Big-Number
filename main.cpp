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

TEST_F(BigNumbersTest, CanMultiply) {
    BigNum::BigNumbers first("24935130");
    BigNum::BigNumbers second("15570");
    
    BigNum::BigNumbers actual = first * second;
    
    BigNum::BigNumbers expected("388239974100");
    
    ASSERT_TRUE((expected == actual));
}

TEST_F(BigNumbersTest, CanDivide) {
    BigNum::BigNumbers first("42300000000");
    BigNum::BigNumbers second("65789");
    
    BigNum::BigNumbers actual = first / second;
    
    BigNum::BigNumbers expected("10");
    
    ASSERT_TRUE((expected == actual));
}

TEST_F(BigNumbersTest, CanGetRemainder) {
    BigNum::BigNumbers first("2470000000000");
    BigNum::BigNumbers second("2470000000000");
    
    BigNum::BigNumbers actual = first % second;
    
    BigNum::BigNumbers expected("0");
    
    ASSERT_TRUE((expected == actual));
}
