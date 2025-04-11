/*
* script: TwoDayPackage.cpp
* action: Contains the two day package class
*		  inheriting from the base package class
* author: D.M
* date: 10APR25
*/

#include <iostream>
#include <string>
#include "TwoDayPackage.h"

using namespace std;

// Default constructor for TwoDayPackage class
TwoDayPackage::TwoDayPackage(const string& sName, 
						     const string& sAddress, 
							 const string& sCity, 
							 const string& sState, 
							 const string& sZip, 
							 const string& rName, 
							 const string& rAddress, 
							 const string& rCity, 
							 const string& rState, 
							 const string& rZip, 
							 double wOunces, 
							 double cPerOunce, 
							 double flatFee)							
							: Package(sName, 
									  sAddress, 
	                                  sCity, 
	                                  sState, 
	                                  sZip,
	                                  rName, 
	                                  rAddress, 
	                                  rCity, 
	                                  rState, 
	                                  rZip,
	                                  wOunces, 
	                                  cPerOunce),
	                                  flatFee(flatFee)
{
	setFlatFee(flatFee);
}


// Copy constructor
TwoDayPackage::TwoDayPackage(const TwoDayPackage& other) : Package(other)
{
	// Initialize private variables from the other object
	this->flatFee = other.flatFee;
	
}


// Destructor
TwoDayPackage::~TwoDayPackage()
{
	// Destructor implementation
	// Not sure if this is needed for memory but included for completeness
	
}


// Setters and getters for the flat fee
void TwoDayPackage::setFlatFee(double)
{
	// Ensure flat fee is greater than 0
	if (flatFee < 0)
	{
		throw invalid_argument("Flat fee must be greater than 0");
	}
}

double TwoDayPackage::getFlatFee() const
{
	return flatFee;
}


// Calculate the cost with flat fee added
double TwoDayPackage::calculateCost() const
{
	// Calculate the total cost including the flat fee
	return (getWeightInOunces() * getCostPerOunce()) + flatFee;
}


// String representation of TwoDayPackage
std::string TwoDayPackage::toString() const
{
	// String representation of the TwoDayPackage

	return std::string() + "TwoDayPackage: \n" +
		"Sender: " + getSenderName() + "\n" +
		"Sender Address: " + getSenderAddress() + "\n" +
		"Sender City: " + getSenderCity() + "\n" +
		"Sender State: " + getSenderState() + "\n" +
		"Sender Zip: " + getSenderZip() + "\n" +
		"Recipient: " + getRecipientName() + "\n" +
		"Recipient Address: " + getRecipientAddress() + "\n" +
		"Recipient City: " + getRecipientCity() + "\n" +
		"Recipient State: " + getRecipientState() + "\n" +
		"Recipient Zip: " + getRecipientZip() + "\n" +
		"Weight (oz): " + std::to_string(getWeightInOunces()) + "\n" +
		"Cost per ounce: $" + std::to_string(getCostPerOunce()) + "\n" +
		"Flat Fee: $" + std::to_string(getFlatFee()) + "\n";
}






