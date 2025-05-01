/*
* script: DuplicateElimination.cpp
* action: This program demonstrates standard library
*         algorithms that uses iterators to eliminate duplicates.
*         The program utilizes OOP techniques to accomplish the task.
* author: D.M
* date: 01MAY25
*/

#include <iostream>
#include <vector>
#include "RemoveDuplicate.h"
using namespace std;

int main()
{
    // Declare test vector to store the user input
    vector<int> testVector;

    // Prompt the user to enter 20 integers
	cout << "Enter 20 integers (duplicates allowed):\n";

	// Loop to read 20 integers from the user
	for (int i = 0; i < 20; ++i)
	{
		// Receives integers from the user
		int input;
		cin >> input;

		// Appends the input to the test vector
		testVector.push_back(input);
	}

    // Create an instance of RemoveDuplicate class
    RemoveDuplicate eliminateDuplicates(testVector);

	// Call the method to check and eliminate duplicates with both methods
    eliminateDuplicates.checkForDuplicates();

	// This method uses the unique_copy algorithm and back_inserter
	eliminateDuplicates.checkForDuplicatesVersionTwo();

    return 0;
}


