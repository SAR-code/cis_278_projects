/*
* script: bmi_calculator.cpp
* action: Takes the user's input weight in pounds and height in inches
*         then calculates and displays the following information from
*         The Department of Health and Human Services/National Institute of Health
* author: D.M
* date: 21JAN25
*/

#include <iostream>
using namespace std;

// initialize variables for user input
float user_weight = 0;
float user_height = 0;


int main()
{
    // display inital menu for user's weight input
    cout << "Enter weight in pounds: ";
    cin >> user_weight;

    // display initial menu for user's height input
    cout << "Enter height in inches: ";
    cin >> user_height;

    // calculates BMI
    float calculate_bmi = (user_weight * 703) / (user_height * user_height);

    // displays user's BMI
    cout << "Your BMI: " << calculate_bmi;

    // displays BMI index stats
    cout << "\n\nBMI VALUES\n";
    cout << "Underweight: less than 18.5\n";
    cout << "Normal: between 18.5 and 24.9\n";
    cout << "Overweight: between 25 and 29.9\n";
    cout << "Obese: 30 or greater";

    
}


