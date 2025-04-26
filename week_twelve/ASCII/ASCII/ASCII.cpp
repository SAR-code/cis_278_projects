/*
* script: ASCII.cpp
* action: This program uses a for statement to print a
*         table of ASCII values in the ASCII charter set
*         from 33 to 126.
* author: D.M
* date: 24APR25
*/

#include <iostream>
#include <iomanip>

// function prototypes
void printTable();

using namespace std;

int main()
{
    
	// invokes the printTable function
	printTable();
}

// Function to organize the ASCII values into a table and print them
void printTable() {

    // prints the table header
	cout << "ASCII Table" << endl;
    cout << left << setw(15) << "Decimal"
         << left << setw(15) << "Octal"
		 << left << setw(20) << "Hexadecimal"
		 << left << setw(15) << "Character" << endl;

	// prints the table divider
	cout << string(59, '*') << endl;
	
	// loops through the ASCII values
	for (int idx = 33; idx <= 126; idx++) {
		cout << left << setw(15) << dec << idx
			<< left << setw(15) << oct << idx
			<< left << setw(20) << hex << idx
			<< left << setw(15) << static_cast<char>(idx) << endl;
	}
}


