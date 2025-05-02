/*
* script: FileReader.cpp
* action: This program uses the istream_iterator<int>,
*         the copy alogrithm and the back_inserter to read the 
*         contents of a text  file that contains int values
*         separated by whitespace
* author: D.M
* date: 01MAY25
*/

#include "ReadFile.h"
#define FILE_NAME "numbers.txt"

int main()
{
    // Create a ReadFile object to read the numbers.txt file
	ReadFile f_reader(FILE_NAME);

	// Call the readDocument method to read the file
	f_reader.readDocument();

	// Call the displayDocument method to display the file content
	f_reader.displayDocument();

	return 0;
}


