/*
* script: RemoveDuplicate.cpp
* action: This contains the implementation of
*         the RemoveDuplicate class.
* author: D.M
* date: 01MAY25
*/

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

#include "RemoveDuplicate.h"

using namespace std;

// Default constructor for RemoveDuplicate class

RemoveDuplicate::RemoveDuplicate(const std::vector<int>& inputArry)
	: inputData(inputArry), originalData(inputArry){}

// Method to check and eliminate duplicates
void RemoveDuplicate::checkForDuplicates()
{
	// Stores the original data for modification
	inputData = originalData;

	// Display the original input data
	cout << "\nThe original vector data:\n";
	copy(inputData.begin(), inputData.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// Sorts the initial input data
	sort(inputData.begin(), inputData.end());

	// Remove duplicates from the sorted data
	auto last = unique(inputData.begin(), inputData.end());

	// Display the data after duplicates have been removed
	cout << "\nAfter duplicates have been removed:\n";
	copy(inputData.begin(), last, ostream_iterator<int>(cout, " "));
	cout << endl;


}

// This method is a version two of the previous method that utilizes
void RemoveDuplicate::checkForDuplicatesVersionTwo()
{
	// Stores the original data for modification
	inputData = originalData;

	// Display the original input data
	cout << "\nThe original vector data in version two:\n";
	copy(inputData.begin(), inputData.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// Sorts the initial input data
	sort(inputData.begin(), inputData.end());

	// removes duplicates from sorted data using unique_copy & back_inserter
	unique_copy(inputData.begin(), inputData.end(), back_inserter(unique_data));

	// Display the data after duplicates have been removed
	cout << "\nAfter duplicates have been removed in version two:\n";
	copy(unique_data.begin(), unique_data.end(), ostream_iterator<int>(cout, " "));
	cout << endl;


}




