/*
* script: WordReader.cpp
* action: This program contains the class
*         implementation for the WordReader class
* author: D.M
* date: 07MAY25
*/

#include "WordReader.h"
#include <iostream>
#include <fstream>

using namespace std;


// Default constructor 
WordReader::WordReader(const std::string& filename) : filename(filename)
{
}

// Copy constructor
WordReader::WordReader(const WordReader& other)
{
	filename = other.filename;
	words = other.words;
	
}

// Method to read the words from a file
bool WordReader::readWords()
{
	// Declares the required variables to read the file
	ifstream infile(filename);
	string word;

	// Checks if the file has an error
	if (!infile) {
		cerr << "Error opening file: " << filename << endl;
		exit(1);
	}

	// If readWords() is called more than once.
	words.clear();

	while (infile >> word) {

		// Convert the word to lowercase
		for (char& character : word) {
			character = tolower(static_cast<unsigned char>(character));
		}

		// Utilizes push_back to add the word to the vector
		words.push_back(word);
	}

	// Closes the file
	infile.close();

	return !words.empty();

}

// Returns the words stored in the vector
const std::vector<std::string>& WordReader::getWords() const
{
	return words;
}



