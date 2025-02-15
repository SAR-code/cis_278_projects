/*
* script: smallest.cpp
* action: This program finds the smallest of several integers.
* author: D.M
* date: 15FEB25
*/

#include <iostream>
using namespace std;


int main()
{
    // declare required variables
    int numbers = 0;
    int smallest_number = 0;
    


    // prompt the user to enter a number
    cout << "Enter a number and we will determine which number is the smallest (enter a negative number to quit)\n";
    cout << "Enter a number: ";

    // retrieves the number the user unput
    cin >> numbers;

    // assumes the inital number entered is the smallest before caring later inputs
    smallest_number = numbers;

    while (numbers >= 0) {

        // continues the prompt until sentinel value is entered
        cout << "Enter a number: ";
        cin >> numbers;

        // compares each user input to determine the smallest value
        if (numbers < smallest_number && numbers >= 0) {
            smallest_number = numbers;
        }
    }

    // displays the smallest numbers;
    cout << "\nThe smallest number entered was " << smallest_number;


    return 0;
}


