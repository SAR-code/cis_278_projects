/*
* script: small_to_large.cpp
* action: The program takes the user's input of three integers and determines
*         the sum, average, product, smallest, and largest integer entered
* author: D.M
* date: 21JAN25
*/

#include <iostream>
using namespace std;

// declare variables for user input

int num_1{ 0 };
int num_2{ 0 };
int num_3{ 0 };



int main()
{
    // Displays the initial menu prompting the user to enter three integers
    cout << "Input three different integers: ";
    cin >> num_1 >> num_2 >> num_3;

    // calculates the sum of the user's input
    int sum = num_1 + num_2 + num_3;

    // calculates the average of the user's input
    int average = sum / 3;

    // calculates the product of the user's input
    int product = num_1 * num_2 * num_3;

    // determines the smallest number out of the input group with nested inputs
    int smallest = min(num_1, min(num_2, num_3));

    // determines the largest number of the input group with nested inputs
    int largest = max(num_1, max(num_2, num_3));

    // displays the results of the integers entered
    cout << "Sum is " << sum;
    cout << "\nAverage is " << average;
    cout << "\nProduct is " << product;
    cout << "\nSmallest is " << smallest;
    cout << "\nLargest is " << largest;

    return 0;
}


