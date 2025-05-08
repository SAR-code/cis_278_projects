/*
* script: WordReader.h
* action: This program contains the class
*         definition for the WordReader class
* author: D.M
* date: 07MAY25
*/

#ifndef WORDREADER_H
#define WORDREADER_H

#include <string>
#include <vector>

class WordReader {
public:

	// Default constructor
	WordReader(const std::string& filename);

	// Copy constructor
	WordReader(const WordReader& other);

	// Methods to read words from a file
	bool readWords();

	// Stores the words in a vector
	const std::vector<std::string>& getWords() const;

private:

	// Declare private variables
	std::string filename;
	std::vector<std::string> words;
	
};

#endif
