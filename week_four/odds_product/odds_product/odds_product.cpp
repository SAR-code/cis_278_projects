/*
* script: odds_product.cpp
* action: This program calculates the product of the odd integers from 
*         1-15
* author: D.M
* date: 15FEB25
*/

#include <iostream>
using namespace std;
int main()
{
    // intialize required variables
    int number = 0;
    int product = 1;

    // iterates and multiplies through odd numbers 1-15
    for (number = 1; number <= 15; number += 2) {
        product = product * number;

        //outputs the product of each odd number
        cout << "\n" << product;
    }

    // displays the final product 
    std::cout << "\nThe final product is: " << product;

    return 0;
}


