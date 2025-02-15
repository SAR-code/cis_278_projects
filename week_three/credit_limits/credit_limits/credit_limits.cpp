/*
* script: credit_limits.cpp
* action: This program determines whether a customer exceeded the credit limit
*         on a charge account.
* author: D.M
* date: 04FEB25
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    // declare initial variables required
    int userAccount;
    float beginningBal;
    float totalCharges;
    float totalCredits;
    float creditLimit;
    

    // Prompt the user to enter account number
    cout << "Enter account number (or -1 to quit): ";
    cin >> userAccount;

    // establish while loop to interact with the account
    while (userAccount != -1) {

        // prompt the user to enter beginning balance
        cout << "Enter beginning balance: ";
        cin >> beginningBal;

        // prompt user to enter total charges
        cout << "Enter total charges: ";
        cin >> totalCharges;

        //prompt user to enter total credits
        cout << "Enter total credits: ";
        cin >> totalCredits;

        // promt user to enter credit limit
        cout << "Enter credit limit: ";
        cin >> creditLimit;

        // calculates new balance
        float newBalance = beginningBal + totalCharges - totalCredits;

        // display updated bank info
        cout << "New balance is " << newBalance << endl;
   
        // displays updated bank info if credit limit exceeded
        if (newBalance > creditLimit) {
            cout << "Account: " << fixed << setprecision(2) << userAccount << endl;
            cout << "Credit limit: " << fixed << setprecision(2) << creditLimit << endl;
            cout << "Balance: " << fixed << setprecision(2) << newBalance << endl;
            cout << "Credit Limit Exceeded";
        }

        cout << "\n\nEnter account number (or -1 to quit): ";
        cin >> userAccount;
    }

    

    return 0;
}


