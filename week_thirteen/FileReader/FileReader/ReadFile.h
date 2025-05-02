/*
* script: ReadFile.h
* action: This program contains the ReadFile class
*         definition
* author: D.M
* date: 01MAY25
*/

#include <iostream>
#include <vector>

#ifndef READFILE_H
#define READFILE_H

class ReadFile
{
public:

	// Default constructor
	ReadFile(const std::string& fileName);


	// Declared method to read the file
	void readDocument();

	// Declared method to display the file content
	void displayDocument();

private:

	// Declare private data members
	std::string fileName;
	std::vector<int> fileContent;
};

#endif
