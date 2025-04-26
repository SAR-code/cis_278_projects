/*
* script: ToolData.h
* action: This is contains the ToolData class definition.
* author: D.M
* date: 24APR25
*/


#include <iostream>
#include <string>

#ifndef TOOLDATA_H
#define TOOLDATA_H



class ToolData
{

public:

	// default constructor
	ToolData(int = 0, const std::string& = "", int = 0, double = 0.0);


	// methods for tool data class

	// setters and getters for record number
	void setRecordNumber(int);
	int getRecordNumber() const;

	// setters and getters for tool name
	void setToolName(const std::string&);
	std::string getToolName() const;

	// setters and getters for quantity
	void setQuantity(int);
	int getQuantity() const;

	// setters and getters for cost
	void setCost(double);
	double getCost() const;

	// string representation of the object
	std::string toString() const;
	
private:

	// declare required data members
	int recordNumber;
	char toolName[25];
	int quantity;
	double cost;
};

#endif