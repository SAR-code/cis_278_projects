/*
* script: Backwards.cpp
* action: This program receives a string from the user
          and converts all lowercase to uppercase and
          all uppercase to lowercase and then reverses
          the input.
* author: D.M
* date: 07MAY25
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function prototype
void reverseString(string& userInput);

int main()
{
    
    // Declare a string variable to hold the user input
    string user_input;

    // Prompt the user to enter a string
    cout << "Enter a string: ";

    // Get the user input
    getline(cin, user_input);

    // Invoke the function with the user input
    reverseString(user_input);

    return 0;
}

// Declare a function to reverse and convert the string
void reverseString(string& userInput)
{
    // Loop through the string backwards
    for (int i = userInput.length() - 1; i >= 0; i--)
    {
        // Get the current character
        char currentChar = userInput[i];

        // Check if the character is lowercase
        if (islower(currentChar))
        {
            // Converts to uppercase
            cout << static_cast<char>(toupper(currentChar));
        }
        else if (isupper(currentChar))
        {
            // Converts to lowercase
            cout << static_cast<char>(tolower(currentChar));
        }
        else
        {
            // If it's neither, just print the character as is
            cout << currentChar;
        }
    }
    cout << endl;
}


