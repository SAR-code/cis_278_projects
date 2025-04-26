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

enum class Choice {NEW = 1, ADD, PRINT, UPDATE, DELETE, END};

// function prototypes
Choice enterChoice();
void updateToolDataFile();
void writeToolDataToFile();
void readToolDataFromFile();
void deleteToolRecord();
void initializeFile();
void loadSeededData();

int main()
{

	// display notes
	cout << "If you have not created a .dat file first, select option 1 to begin\n";
	cout << "If you already have a .dat file selecting option 1 will reset the record\n";

	// stores user choice
	Choice choice;

	// prompts the user to select a certain action
	while ((choice = enterChoice()) != Choice::END) {
		switch (choice) {
		case Choice::NEW:
		     	initializeFile();
			break;
		case Choice::ADD:
			writeToolDataToFile();
			break;
		case Choice::PRINT:
			readToolDataFromFile();
			break;
		case Choice::UPDATE:
			updateToolDataFile();
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
	
	// displays menu to the user
	cout << "\nEnter your choice\n"
		<< "1 - Initialize default file (resets existing file)\n"
		<< "2 - Add or Edit tool inventory\n"
		<< "3 - List all inventory\n"
		<< "4 - Update a record\n"
		<< "5 - Delete record\n"
		<< "6 - End Program\n";

	// declare variable to capture user response
	int menuChoice;

	// returns the user response
	cin >> menuChoice;
	return static_cast<Choice>(menuChoice);
}


// Initializes file with 100 empty records and seeded the data
void initializeFile() {

	// open the file
	ofstream file(FILE_NAME, ios::out | ios::binary);

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

		// create a ToolData object with the user input (move this up)
		ToolData inventory(recordNum, toolName, quantity, cost);

		// seek position in file of user input record
		outToolData.seekp(inventory.getRecordNumber() * sizeof(ToolData), ios::beg);

		// write the object to the file
		outToolData.write(reinterpret_cast<const char*>(&inventory), sizeof(ToolData));

		// prompt the user to input another record number
		cout << "Enter record number\n";
		cin >> recordNum;
	}

	// closes file
	outToolData.close();
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
	for (int idx{ 0 }; idx < 100; ++idx) {
		inToolData.read(reinterpret_cast<char*>(&tool), sizeof(ToolData));
		if (tool.getRecordNumber() != 0) {
			cout << left << setw(14) << tool.getRecordNumber()
				<< left << setw(22) << tool.getToolName()
				<< left << setw(15) << tool.getQuantity()
				<< fixed << setprecision(2)
				<< left << setw(15) << tool.getCost() << endl;
		}
	}

	inToolData.close();
}

// Function updates a tool based on record number
void updateToolDataFile() {

	// opens the file
	fstream updateFile(FILE_NAME, ios::in | ios::out | ios::binary);

	// exit the program if errors occur
	if (!updateFile) {
		cerr << "Error opening file: " << endl;
		exit(EXIT_FAILURE);
	}

	// initialize ToolData
	ToolData tool;
	int recordId = tool.getRecordNumber();

	// prompt the user to enter the inventory record number
	cout << "Enter record ID of tool to update (1 - 100): ";
	cin >> recordId;
	

	// checks to see if ID is out of bounds
	if (recordId < 0 || recordId >= 100) {
		cout << "Invalid record ID\n";
		return;
	}

	// searches inventory for tool ID
	updateFile.seekg(recordId * sizeof(ToolData), ios::beg);
	updateFile.read(reinterpret_cast<char*>(&tool), sizeof(ToolData));

	// if tool does not have an Id
	if (tool.getRecordNumber() == 0) {
		cout << "No tool with this ID.\n";
		return;
	}

	// display found tool name
	cout << "Current tool: " << tool.getToolName() << '\n';
	cout << "Enter new tool (select ENTER to keep the same tool): ";
	cin.ignore();
	string newTool;
	getline(cin, newTool);

	// sets the new tool if not empty
	if (!newTool.empty()) {
		tool.setToolName(newTool);
	}

	// display found tool quantity
	int newNum;
	cout << "Current quantity: " << tool.getQuantity() << '\n';
	cout << "Enter new quantity: ";
	cin >> newNum;
	tool.setQuantity(newNum);

	// display found tool cost
	double newCost;
	cout << "Current cost: " << tool.getCost() << '\n';
	cout << "Enter new cost: ";
	cin >> newCost;
	tool.setCost(newCost);

	// manages the file then closes
	updateFile.seekp(recordId * sizeof(ToolData), ios::beg);
	updateFile.write(reinterpret_cast<char*>(&tool), sizeof(ToolData));
	updateFile.close();

	// display message
	cout << "Tool Updated \n";


}

// Function deletes a selected record
void deleteToolRecord() {
	
	// opens the file
	fstream deleteFile(FILE_NAME, ios::in | ios::out | ios::binary);

	// exit the program if errors occur
	if (!deleteFile) {
		cerr << "Error opening file: " << endl;
		exit(EXIT_FAILURE);
	}

	ToolData tool;
	int recordId = tool.getRecordNumber();

	// prompt the user to delete the record selected
	cout << "Enter tool record ID to delete (1 - 100): ";
	cin >> recordId;

	// checks the records to see if ID is out of bounds
	if (recordId < 0 || recordId >= 100) {
		cout << "Invalid record number.\n";
		return;
	}

	// manages the files pointer to confirm tool exists
	deleteFile.seekg(recordId * sizeof(ToolData), ios::beg);
	deleteFile.read(reinterpret_cast<char*>(&tool), sizeof(ToolData));

	// inspects the record for non existent IDs
	if (tool.getRecordNumber() == 0) {
		cout << "Tool doesn't exist. Record number #" << recordId << ".\n";
		deleteFile.close();
		return;
	}

	// overwrite tools with a blank record
	ToolData blankRecord = { 0, "", 0, 0.0 };
	deleteFile.seekp(recordId * sizeof(ToolData), ios::beg);
	deleteFile.write(reinterpret_cast<char*>(&blankRecord), sizeof(ToolData));
	deleteFile.close();

	cout << "Tool deleted successfully\n";
}

// Function preloads information already stored in the inventory
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

	// iterates through the seeded data
	for (const auto& tool : seededData) {

		seededFile.seekp(tool.getRecordNumber() * sizeof(ToolData), ios::beg);
		seededFile.write(reinterpret_cast<const char*>(&tool), sizeof(ToolData));
			
	}

	// closes file
	seededFile.close();

	// display message
	cout << "Seeded data loaded successfully";

}
