//
//  BigNumbersLib.cpp
//  BigNumbersLibrary
//
//  Created by Giles Carlos on 5/13/19.
//  Copyright © 2019 Giles Carlos. All rights reserved.
//

#include "BigNumbersLib.h"
#include "math.h"

namespace BigNum {
    BigNumbers::BigNumbers(std::string stringNumber) {
        int s;
        
        for (char c : stringNumber) {
            // Convert each character in string to unsigned long long integer
            s = std::strtoull(&c, NULL, 0);
            
            //push each integer to the back of the digit vector
            if (s > -1 && s < 10) {
                digits.push_back(s);
            }
        }
    }
    
    //print out the number
    std::string BigNumbers::print() {
        //create string to store digits
        std::string stringNumber;
        
        //concatenate the string by converting each digit in the vector to a char
        for (int i = 0; i < digits.size(); i++) {
            stringNumber += std::to_string(digits.at(i));
        }
        
        return stringNumber;
    }
    
    //assignment operator
    BigNumbers & BigNumbers::operator =(const BigNumbers &x) {
        //assign each digit from x to this BigNumber and make sign the same
        for(int i = 0; i < x.digits.size(); i++)
            digits.push_back(x.digits[i]);
        return (*this);
    }
    
    //addition operator
    BigNumbers BigNumbers::operator +(const BigNumbers & right) {
        //initialize variables to be used later on
        int carry = 0;
        int temporarySum = 0;
        std::string sum = "";
        int leftNumberOfDigits = digits.size();
        int rightNumberOfDigits = right.digits.size();
        //compare length of the two numbers to be added
        bool rightIsLonger = (rightNumberOfDigits > leftNumberOfDigits);
        //find difference in digits
        int digitDiff = std::abs((int)(rightNumberOfDigits - leftNumberOfDigits));
        
        //create vectors to store digits of the longer and shorter number
        const std::vector<int>* shorterNumber;
        const std::vector<int>* longerNumber;
        
        //assign digits vector to ones just created
        if (rightIsLonger) {
            longerNumber = &right.digits;
            shorterNumber = &digits;
        } else {
            longerNumber = &digits;
            shorterNumber = &right.digits;
        }
        
        //start from back of the vector and decrease until reaching the front
        for (int i = longerNumber->size() - 1; i >= 0; i--) {
            //if the shorter number has enough a digit at the position
            if (i >= digitDiff) {
                temporarySum = carry + shorterNumber->at(i - digitDiff)  + longerNumber->at(i);
            } else {
                temporarySum = carry + longerNumber->at(i);
            }
            
            //if the sum of the two numbers is double digit, carry it to the next index
            if (temporarySum > 9) {
                carry = 1;
                temporarySum -= 10;
            } else
                carry = 0;
            //at temporary sum to the current sum
            sum = std::to_string(temporarySum) + sum;
        }
        //if a carry digit is still leftover
        if (carry > 0) {
            sum = "1" + sum;
        }
        return BigNumbers(sum);
    }
    
    //subtraction operator
    BigNumbers BigNumbers::operator -(const BigNumbers & right) {
        //initialize variables to be used later on
        int carry = 0;
        int tempDifference = 0;
        std::string difference = "";
        
        //find difference in size between the two numbers
        int digitDiff = std::abs((int)(right.digits.size() - digits.size()));
        
        //create vectors to store digits of the longer and shorter number
        const std::vector<int>* shorterNumber;
        const std::vector<int>* longerNumber;
        
        if (right >= *this) {
            longerNumber = &right.digits;
            shorterNumber = &digits;
        } else {
            longerNumber = &digits;
            shorterNumber = &right.digits;
        }
        
        int topDigit, bottomDigit;
        //start from back of the vector and decrease until reaching the front
        for (int position = longerNumber->size() - 1; position >= 0; position--) {
            topDigit = longerNumber->at(position);
            if (position >= digitDiff) {
                bottomDigit = shorterNumber->at(position - digitDiff);
                
                if (bottomDigit > topDigit) {
                    tempDifference = (10 + topDigit + carry) - bottomDigit;
                    carry = -1;
                }
                else if (bottomDigit == topDigit) {
                    if (carry == 0) {
                        tempDifference = topDigit - bottomDigit;
                    } else {
                        tempDifference = (10 + topDigit + carry) - bottomDigit;
                        carry = -1;
                    }
                } else {
                    
                    tempDifference = (topDigit + carry) - bottomDigit;
                    carry = 0;
                }
            }
            else {
                //extra digits from left or right
                if (topDigit > 0) {
                    tempDifference = carry + topDigit;
                    carry = 0;
                }
                else {
                    if (carry == 0) {
                        tempDifference = 0;
                    }
                    else {
                        tempDifference = 9;
                        carry = -1;
                    }
                }
            }
            difference = std::to_string(tempDifference) + difference;
        }
        
        // remove leading zeros
        std::string realDifference;
        bool leadingZerosSkipped = false;
        
        for (char c : difference) {
            if (c != '0' && !leadingZerosSkipped) {
                realDifference += c;
                leadingZerosSkipped = true;
            } else if (leadingZerosSkipped) {
                realDifference += c;
            }
        }
        
        //if all zeros set to 0
        if (realDifference.size() == 0)
            realDifference = "0";
        return BigNumbers(realDifference);
    }
   
    //equality operator
    bool operator ==(const BigNumbers & left, const BigNumbers & right) {
        if (left.digits.size() != right.digits.size()) return false;
        
        if (left.digits.size() == 1) return left.digits.at(0) == right.digits.at(0);
        
        for (int place = left.digits.size() - 1; place > 0; place--) {
            if (left.digits.at(place) != right.digits.at(place)) {
                return false;
            }
        }
        return true;
    }
    
    //greater than operator
    bool operator >(const BigNumbers & left, const BigNumbers & right) {
        int leftDigits = left.digits.size();
        int rhsDigits = right.digits.size();
        
        //compare size of BigNumbers
        if (leftDigits != rhsDigits) {
            return (leftDigits > rhsDigits);
        }
        
        for (int i = 0; i < leftDigits; i++) {
            if (left.digits.at(i) < right.digits.at(i)) {
                return false;
            } else if (left.digits.at(i) > right.digits.at(i)) {
                return true;
            } else if (i == leftDigits) {
                if (left.digits.at(i) == right.digits.at(i)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    //greater than or equal to operator
    bool operator >=(const BigNumbers & left, const BigNumbers & right) {
        return (left > right) || left == right;
    }
    
}
