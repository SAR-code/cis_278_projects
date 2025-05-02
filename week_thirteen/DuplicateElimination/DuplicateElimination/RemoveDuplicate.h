/*
* script: RemoveDuplicate.h
* action: This contains the header file for
*         the RemoveDuplicate class.
* author: D.M
* date: 01MAY25
*/

#include <iostream>


#ifndef REMOVEDUPLICATE_H
#define REMOVEDUPLICATE_H

class RemoveDuplicate
{

public:
	// Default constructor for RemoveDuplicate class
	RemoveDuplicate(const std::vector<int>& inputArry);

	// Declare method to check and eliminate duplicates
	void checkForDuplicates();

	// This method is a version two of the previous method that utilizes
	// the unique_copy algorithm and back_inserter

	void checkForDuplicatesVersionTwo();

private:

	// Declare private data members to store input
	std::vector<int> inputData;

	// Declare private data members to store unique data
	std::vector<int> unique_data;

	// Declare private data member to preserve original data
	const std::vector<int> originalData;
	
};





#endif
