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
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "ToolData.h"

//#define FILE_NAME "hardware.dat"
using namespace std;

// function prototypes
void displayToolHeader();
void createToolDataFile();
void writeToolDataToFile();
void readToolDataFromFile();

int main()
{
	// declare test variables
	
	//int recordNum = 1;
	//string toolName = "Hammer";
	//int quantity = 10;
	//double cost = 15.99;

	//// test the ToolData class

	////ToolData toolData(recordNum, toolName, quantity, cost);
	//ToolData toolData(1, "Hammer", 10, 15.99);

	//// display the header
	//displayToolHeader();

	//cout << toolData.getRecordNumber() << endl;

	// invoke function to create the empty file
	createToolDataFile();

	// invoke function to write tool data to file
	writeToolDataToFile();

	// invoke function to read tool data for accurracy
	readToolDataFromFile();

    return 0;
}


void displayToolHeader()
{
	// display the header for the tool data
	cout << "Record Number\tTool Name\tQuantity\tCost" << endl;
	cout << "****************************************************" << endl;
}

void createToolDataFile()
{
	// open the file in binary mode
	ofstream outToolData{ "hardware.dat", ios::out | ios::binary};

	// exit program if ofstream can't open file
	if (!outToolData)
	{
		cerr << "Error opening file: " << endl;
		exit(EXIT_FAILURE);
	}

	// create an empty ToolData object
	ToolData emptyToolData;

	// write 100 empty records to the file
	for (int idx{ 0 }; idx < 100; ++idx)
	{
		// write the empty object to the file
		outToolData.write(reinterpret_cast<const char*>(&emptyToolData), sizeof(ToolData));
	}
}

void writeToolDataToFile(){

	// open the file in binary mode
	fstream outToolData{ "hardware.dat", ios::in | ios::out | ios::binary};

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



}

void readToolDataFromFile() {
	fstream inToolData{ "hardware.dat", ios::in | ios::binary };

	if (!inToolData) {
		cerr << "Error opening file.\n";
		exit(EXIT_FAILURE);
	}

	ToolData tool;

	// Prints header
	cout << left << setw(15) << "\nRecord #"
		<< left << setw(22) << "Tool Name"
		<< left << setw(15) << "Quantity"
		<< left << setw(15) << "Cost" << "\n";

	// loopa through the inventory in the file
	while (inToolData.read(reinterpret_cast<char*>(&tool), sizeof(ToolData))) {
		cout << left << setw(14) << tool.getRecordNumber()
			<< left << setw(22) << tool.getToolName()
			<< left << setw(15) << tool.getQuantity()
			<< fixed << setprecision(2)
			<< left << setw(15) << tool.getCost() << endl;
	}
}

