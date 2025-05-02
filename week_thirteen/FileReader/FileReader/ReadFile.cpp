/*
* script: ReadFile.cpp
* action: This program contains the implementation
*         of the ReadFile class
* author: D.M
* date: 01MAY25
*/

#include "ReadFile.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

// Default constructor
ReadFile::ReadFile(const std::string& fileName) :fileName(fileName) {}

// Method to read the file
void ReadFile::readDocument() {

	// Open the file
	ifstream inputFile(fileName);

	// Checks to see if the file is a valid file
	if (!inputFile) {
		cerr << "Error onpening file: : " << fileName << endl;
		exit(1);
	}

	// Create an istream_iterator to read the ints from the file
	istream_iterator<int> fileIterator(inputFile);
	istream_iterator<int> endOfStream;

	// Copy the contents of the file to the vector
	copy(fileIterator, endOfStream, back_inserter(fileContent));

}

// Method to display the file content
void ReadFile::displayDocument() {

	// Display the contents of the vector
	cout << "The contents of the file are: " << endl;

	// copy the contents with the ostream_iterator
	copy(fileContent.begin(), fileContent.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

