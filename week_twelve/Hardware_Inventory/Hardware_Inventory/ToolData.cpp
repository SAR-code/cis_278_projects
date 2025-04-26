/*
* script: ToolData.cpp
* action: This is contains the ToolData implementation.
* author: D.M
* date: 24APR25
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "ToolData.h"

using namespace std;

// default constructor for ToolData class
ToolData::ToolData(int recordNum, const string& tName, int qty, double price)
	: recordNumber(recordNum), quantity(qty), cost(price)
{
	// initialize the data members
	setRecordNumber(recordNum);
	setQuantity(qty);
	setCost(price);
	strncpy_s(toolName, tName.c_str(), sizeof(toolName));
	toolName[sizeof(toolName) - 1] = '\0';

}


// setters and getters for record number
void ToolData::setRecordNumber(int recordNum)
{
	recordNumber = recordNum;
}

int ToolData::getRecordNumber() const
{
	return recordNumber;
}


// setters and getters for tool name
void ToolData::setToolName(const string& tName)
{

	size_t length{ tName.size() };
	length = (length < 25) ? length : 24;
	tName.copy(toolName, length);
	toolName[length] = '\0'; // null-terminate the string
}

string ToolData::getToolName() const
{
	return toolName;
}

// setters and getters for quantity
void ToolData::setQuantity(int qty)
{
	quantity = qty;
}

int ToolData::getQuantity() const
{
	return quantity;
}

// setters and getters for cost
void ToolData::setCost(double price)
{
	cost = price;
}

double ToolData::getCost() const
{
	return cost;
}


// string representation of the object
string ToolData::toString() const
{
	ostringstream oss;

	oss << "Record Number: " << recordNumber << "\n"
		<< "Tool Name: " << toolName << "\n"
		<< "Quantity: " << quantity << "\n"
		<< fixed << setprecision(2)
		<< "Cost: $" << cost << endl;

	return oss.str();
}


