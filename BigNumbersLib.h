/** @file BigNumbersLib.h
 *  @brief Header file for BigNumbers
 *
 *  Contains the function declarations for the BigNumbers class
 *
 *
 *  @author Giles Carlos
 */

#ifndef BigNumbersLib_h
#define BigNumbersLib_h

#include <vector>
#include <string>
#include <iostream>

namespace BigNum
{
    class BigNumbers {
    private:
        /** @brief Vector to store digits of the big number */
        std::vector <int> digits;
        
    public:
        /*
            @brief Constructor
            @param stringNumber The string to be converted into digits stored as a vector
        */
        BigNumbers(std::string stringNumber);
        
        /*
         @brief Default Constructor
        */
        BigNumbers();
        
        /*
         @brief Assigns this big number to another big number
         @param right The right side of the mathematical equation.
         @return  This big number, a copy of the right.
        */
        BigNumbers & operator =(const BigNumbers & right);
        
        /*
         @brief Adds two big numbers
         @param right The right side of the mathematical equation.
         @return  The sum of the two big numbers.
        */
        BigNumbers operator +(const BigNumbers &right);
        
        /*
         @brief Subtracts two big numbers
         @param right The right side of the mathematical equation.
         @return  The difference of the two big numbers.
        */
        BigNumbers operator -(const BigNumbers &right);
        
        /*
            @brief Multiplies two big numbers
            @param right The right side of the mathematical equation.
            @return  The product of the two big numbers.
        */
        BigNumbers operator *(const BigNumbers &right);
        
        /*
         @brief Divides two big numbers
         @param right The right side of the mathematical equation.
         @return  The quotient of the two big numbers.
         */
        BigNumbers operator /(const BigNumbers &right);
        
        /*
         @brief Divides and returns the remainder of two big numbers
         @param right The right side of the mathematical equation.
         @return  The remainder of the two big numbers.
        */
        BigNumbers operator %(const BigNumbers &right);
        
        /*
         Prints out the big number to the console.
        */
        std::string print();
        
        /*
         @brief Compares two BigNumbers and returns true if equal, false if not
         @param left First BigNumber to be compared
         @param right Second BigNumber to be compared
         @return  True or false.
        */
        friend bool operator ==(const BigNumbers & left, const BigNumbers & right);
        
        /*
         @brief Compares two BigNumbers and returns true if first is greater than the second, false if not
         @param left First BigNumber to be compared
         @param right Second BigNumber to be compared
         @return  True or false.
        */
        friend bool operator >(const BigNumbers & left, const BigNumbers & right);
        
        /*
         @brief Compares two BigNumbers and returns true if first is greater than or equal to the second, false if not
         @param left First BigNumber to be compared
         @param right Second BigNumber to be compared
         @return  True or false.
        */
        friend bool operator >=(const BigNumbers & left, const BigNumbers & right);
    };
}

#endif /* BigNumbersLib_h */
