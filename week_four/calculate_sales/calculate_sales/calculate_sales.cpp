/*
* script: calculate_sales.cpp
* action: This program determines the retail price for each product.
*         The total retail value will be calculated and displayed
* author: D.M
* date: 15FEB25
*/

#include <iostream>
#include "DollarAmount.h"



int main()
{
    // declare required variables
     double productOne{ 2.98 };
     double productTwo{ 4.50 };
     double productThree{ 9.98 };
     double productFour{ 4.49 };
     double productFive{ 6.87 };

    // variables we want to track
    int productNumber{ 0 };
    int quantitySold{ 0 };
    int totalProductsSold{ 0 };
    double price{ 0.0 };
    

    // class object to track total retail value
    DollarAmount totalRetail;

    // initialize while loop to start the program
    while (true) {

        //prompts the user for input
        std::cout << "Enter product number (1-5), or 0 to quit: ";
        std::cin >> productNumber;


        // checks for sentinal value
        if (productNumber == 0) {
            break;
        }

        // checks to ensure valid product number
        if (productNumber < 1 || productNumber > 5) {
            std::cout << "We don't have a product number, enter a number between 1 and 5!\n";
            continue;
        }

        // prompts the user to enter the quantity sold

        std::cout << "Enter quantity sold: ";
        std::cin >> quantitySold;

        // utilize switch statements to determine retail value

        switch (productNumber) {
        case 1:
            price = productOne;
            break;

        case 2:
            price = productTwo;
            break;

        case 3:
            price = productThree;
            break;

        case 4:
            price = productFour;
            break;

        case 5:
            price = productFive;
            break;
        
        default:
            std::cout << "Invalid product number!\n" << std::endl;
            continue;
        }

        // calculate total retail value
        int totalCents = (price * 100 + 0.5);
        DollarAmount productValue = DollarAmount::fromChange(totalCents * quantitySold);

        totalRetail.add(productValue);

        // tallies the total products sold
        totalProductsSold += quantitySold;

        // displays the product number and the amount sold
        std::cout << "Product " << productNumber << ": " << quantitySold
            << " products sold, total retail value: " << productValue.print() << std::endl;
   
    }

    // displays the grand total of all products sold and quantity total
    std::cout << "\nGrand total of all products sold: " << totalRetail.print() << "Total items sold: " << totalProductsSold << std::endl;
    

    
    return 0;
}


