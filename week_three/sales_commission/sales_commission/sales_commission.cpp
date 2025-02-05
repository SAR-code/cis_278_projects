/*
* script: sales_commission.cpp
* action: This program inputs each salesperson's gross sales for the last week and
*         calculates and displays that salesperson's earnings
* author: D.M
* date: 05FEB25
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // initialize required variables
    float salesMade;
    float commission;

    // prompt user to enter sales data
    cout << "Enter sales in dollars (-1 to end): ";
    cin >> salesMade;

    // establish while loop to start up the program for commission entry
    while (salesMade != -1) {

        // calculates the commission
        commission = 0.09 * salesMade + 200;

        // displays commission in the dollar format
        cout << "Salary is: $" << fixed << setprecision(2) << commission << endl;

        // prompts the user for the next input
        cout << "\nEnter sales in dollars (-1 to end): ";
        cin >> salesMade;

    }


    return 0;
}


