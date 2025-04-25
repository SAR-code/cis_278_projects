/*
* script: Hardware_Inventory.cpp
* action: This program initializes the random-access file
*         hardware.dat into 100 empty records and allows
*         the user to add, delete, update, and display tool records.
* author: D.M
* date: 24APR25
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "ToolData.h"

#define FILE_NAME "hardware.dat"
using namespace std;

enum class Choice {NEW = 1, UPDATE, PRINT, DELETE, END};

// function prototypes
Choice enterChoice();
void createToolDataFile();
void updateToolDataFile();
void writeToolDataToFile();
void readToolDataFromFile();
void deleteToolRecord();

void initializeFile();
void loadSeededData();

int main()
{
	// open file for reading and writing
	fstream outToolData{ FILE_NAME, ios::in | ios::out | ios::binary };

	// exit program if file cannot be open
	if (!outToolData) {
		cerr << "File cannot be opened." << endl;
		exit(EXIT_FAILURE);
	}

	// display notes
	cout << "If you have not created a .dat file first, select option 1 to begin\n";
	cout << "If you already have a .dat file selecting option 1 will clear the record\n";

	// stores user choice
	Choice choice;

	// prompts the user to select a certain action
	while ((choice = enterChoice()) != Choice::END) {
		switch (choice) {
		case Choice::NEW:
				initializeFile();
				break;
		case Choice::UPDATE:
				writeToolDataToFile();
				break;
		case Choice::PRINT:
			    readToolDataFromFile();
				break;
		case Choice::DELETE:
				deleteToolRecord();
				break;
		default:
			cerr << "Invalid choice" << endl;
			break;
				
		}
	}


    return 0;
}


// Function to handle user choice
Choice enterChoice() {
	
	cout << "\nEnter your choice\n"
		<< "1 - Initialize default file (resets existing file)\n"
		<< "2 - Write to file\n"
		<< "3 - List all inventory\n"
		<< "4 - Delete record\n"
		<< "5 - End Program\n";

	int menuChoice;

	cin >> menuChoice;
	return static_cast<Choice>(menuChoice);
}


// Initializes file with 100 empty records and seeded the data
void initializeFile() {

	// open the file
	fstream file(FILE_NAME, ios::out | ios::binary);

	// exit the program if errors occur
	if (!file) {
		cerr << "Error opening file: " << endl;
		exit(EXIT_FAILURE);
	}

	// empty tool data object
	ToolData emptyRecords;

	// write 100 empty records to the file
	for (int idx{ 0 }; idx < 100; ++idx)
	{
		// write the empty object to the file
		file.write(reinterpret_cast<const char*>(&emptyRecords), sizeof(ToolData));
	}

	file.close();

	// invoke preloaded records
	loadSeededData();

	// display message
	cout << "\nFile have been initialized.\n";

}


// Function to write data to a .dat file
void writeToolDataToFile(){

	// open the file in binary mode
	fstream outToolData{ FILE_NAME, ios::in | ios::out | ios::binary};

	// exit program if fstream can't open file
	if (!outToolData)
	{
		cerr << "Error opening file: " << endl;
		exit(EXIT_FAILURE);
	}

	// prompt the user to input tool data
	cout << "Enter tool record number. (0 to end input)\n";

	// declare variables to store the user input
	int recordNum;
	string toolName;
	int quantity;
	double cost;

	// prompt the user to input record number
	cin >> recordNum;

	// loop until the user enters 0 for record number
	while (recordNum > 0 && recordNum <= 100)
	{
		// prompt the user to input tool data
		cout << "Enter tool name: \n";
		cin.ignore();
		getline(cin, toolName);
		cout << "Enter quantity: \n";
		cin >> quantity;
		cout << "Enter cost: \n";
		cin >> cost;

		// create a ToolData object with the user input
		ToolData inventory(recordNum, toolName, quantity, cost);

		// seek position in file of user input record
		outToolData.seekp((inventory.getRecordNumber() - 1) * sizeof(ToolData));

		// write the object to the file
		outToolData.write(reinterpret_cast<const char*>(&inventory), sizeof(ToolData));

		// prompt the user to input another record number
		cout << "Enter record number\n";
		cin >> recordNum;
	}

	outToolData.clear();
}


// Function to list all the tools in the .dat
void readToolDataFromFile() {

	// opens the file
	fstream inToolData{ FILE_NAME, ios::in | ios::binary };

	// checks for erros
	if (!inToolData) {
		cerr << "Error opening file.\n";
		exit(EXIT_FAILURE);
	}

	// Initializes empty constructor
	ToolData tool;

	// Prints header
	cout << left << setw(15) << "\nRecord #"
		<< left << setw(22) << "Tool Name"
		<< left << setw(15) << "Quantity"
		<< left << setw(15) << "Cost" << "\n";

	// loops through the inventory in the file
	while (inToolData.read(reinterpret_cast<char*>(&tool), sizeof(ToolData))) {
		cout << left << setw(14) << tool.getRecordNumber()
			<< left << setw(22) << tool.getToolName()
			<< left << setw(15) << tool.getQuantity()
			<< fixed << setprecision(2)
			<< left << setw(15) << tool.getCost() << endl;
	}
}

void deleteToolRecord() {
	cout << "Hello";
}

void loadSeededData() {

	// opens the file
	fstream seededFile(FILE_NAME, ios::in | ios::out | ios::binary);

	// checks for errors with the file
	if (!seededFile) {
		cout << "Errors with the data, initialize file first.\n";
		exit(EXIT_FAILURE);
	}

	// declares the preloaded data
	ToolData seededData[] = {
		{3, "Electric Sander", 7, 57.98},
		{17, "Hammer", 76, 11.99},
		{24, "Jig Saw", 21, 11.00},
		{39, "Lawn Mower", 3, 79.50},
		{56, "Power Saw", 18, 99.99},
		{68, "Screw Driver", 106, 6.99},
		{77, "Sledge Hammer", 11, 21.50},
		{83, "Wrench", 34, 7.50}
	};

	for (const auto& tool : seededData) {

		seededFile.seekp(tool.getRecordNumber() * sizeof(ToolData), ios::beg);
		seededFile.write(reinterpret_cast<const char*>(&tool), sizeof(ToolData));
			
	}

	seededFile.close();

	// display message
	cout << "Seeded data loaded successfully";

}