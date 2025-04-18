/*
* script: Package.cpp
* action: Contains the Package class and methods
* author: D.M
* date: 18APR25
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdexcept>
#include <sstream>


#include "Package.h"

using namespace std;

// Default constructor for package class
Package::Package(const std::string& sName,
	const std::string& sAddress,
	const std::string& sCity,
	const std::string& sState,
	const std::string& sZip,
	const std::string& rName,
	const std::string& rAddress,
	const std::string& rCity,
	const std::string& rState,
	const std::string& rZip,
	double wOunces,
	double cPerOunce
) : senderName(sName),
senderaddress(sAddress),
senderCity(sCity),
senderState(sState),
senderZip(sZip),
recipientName(rName),
recipientaddress(rAddress),
recipientCity(rCity),
recipientState(rState),
recipientZip(rZip),
weightInOunces(wOunces),
costPerOunce(cPerOunce)
{
	setWeightInOunces(wOunces);
	setCostPerOunce(cPerOunce);

}


// Copy constructor
Package::Package(const Package& other)
{
	// Initilize private variables from the other object
	this->senderName = other.senderName;
	this->senderaddress = other.senderaddress;
	this->senderCity = other.senderCity;
	this->senderState = other.senderState;
	this->senderZip = other.senderZip;
	this->recipientName = other.recipientName;
	this->recipientaddress = other.recipientaddress;
	this->recipientCity = other.recipientCity;
	this->recipientState = other.recipientState;
	this->recipientZip = other.recipientZip;
	this->weightInOunces = other.weightInOunces;
	this->costPerOunce = other.costPerOunce;

}


// Destructor
Package::~Package()
{
	// Not sure if this is needed for memory but included for completeness

}


// Setters and getters for the sender's name
void Package::setSenderName(const std::string& sName)
{
	// set the sender's name
	senderName = sName;
}

std::string Package::getSenderName() const
{
	// return the sender's name
	return senderName;
}


// Setters and getters for the recipient's name
void Package::setRecipientName(const std::string& rName)
{
	// set the recipient's name
	recipientName = rName;
}

std::string Package::getRecipientName() const
{
	// return the recipient's name
	return recipientName;
}


// Setters and getters for the sender's address
void Package::setSenderAddress(const std::string& sAddress)
{
	// set the sender's address
	senderaddress = sAddress;
}

std::string Package::getSenderAddress() const
{
	// return the sender's address
	return senderaddress;
}


//Setters and getters for the recipient's address
void Package::setRecipientAddress(const std::string& rAddress)
{
	// set the recipient's address
	recipientaddress = rAddress;
}

std::string Package::getRecipientAddress() const
{
	// return the recipient's address
	return recipientaddress;
}


// Setters and getters for the sender's city
void Package::setSenderCity(const std::string& sCity)
{
	// set the sender's city
	senderCity = sCity;
}

std::string Package::getSenderCity() const
{
	// return the sender's city
	return senderCity;
}


// Setters and getters for the recipient's city
void Package::setRecipientCity(const std::string& rCity)
{
	// set the recipient's city
	recipientCity = rCity;
}

std::string Package::getRecipientCity() const
{
	// return the recipient's city
	return recipientCity;
}


// Setters and getters for the sender's state
void Package::setSenderState(const std::string& sState)
{
	// set the sender's state
	senderState = sState;
}

std::string Package::getSenderState() const
{
	// return the sender's state
	return senderState;
}


// Setters and getters for the recipient's state
void Package::setRecipientState(const std::string& rState)
{
	// set the recipient's state
	recipientState = rState;
}

std::string Package::getRecipientState() const
{
	// return the recipient's state
	return recipientState;
}


// Setters and getters for the sender's zip code
void Package::setSenderZip(const std::string& sZip)
{
	// set the sender's zip code
	senderZip = sZip;
}

std::string Package::getSenderZip() const
{
	// return the sender's zip code
	return senderZip;
}


// Setters and getters for the recipient's zip code
void Package::setRecipientZip(const std::string& rZip)
{
	// set the recipient's zip code
	recipientZip = rZip;
}

std::string Package::getRecipientZip() const
{
	// return the recipient's zip code
	return recipientZip;
}


// Setters and getters for the weight in ounces
void Package::setWeightInOunces(double wOunces)
{
	// Ensure weight is greater than 0
	if (wOunces < 0)
	{
		throw invalid_argument("Weight must be greater than 0");
	}

}

double Package::getWeightInOunces() const
{
	// return the weight in ounces
	return weightInOunces;
}


// Setters and getters for the cost per ounce
void Package::setCostPerOunce(double cPerOunce)
{
	// Ensure cost per ounce is greater than 0
	if (cPerOunce < 0)
	{
		throw invalid_argument("Cost must be greater than 0");
	}
}

double Package::getCostPerOunce() const
{
	// return the cost per ounce
	return costPerOunce;
}

// Calculate the total cost of the package
double Package::calculateCost() const
{
	return weightInOunces * costPerOunce;

}

// getters for sender info
std::string Package::getSenderInfo() const
{
	return (getSenderName() + "\n " 
		 + "\t" + getSenderAddress() + "\n "
		 + "\t" + getSenderCity() + " "
		  + getSenderState() + ", " 
		  + getSenderZip() + "\n");
}

// getters for recipient info
std::string Package::getRecipientInfo() const
{
	return (getRecipientName() + "\n "
		+"\t   " + getRecipientAddress() + "\n "
		+"\t   " + getRecipientCity() + " "
		+ getRecipientState() + ", "
		+ getRecipientZip() + "\n");
}

// String representation of the package
std::string Package::toString() const
{

	// return the string representation of the package

	ostringstream oss;

	oss << "Sender: " << senderName << "\n"
		<< "Address: " << senderaddress << "\n"
		<< "City: " << senderCity << "\n"
		<< "State: " << senderState << "\n"
		<< "Zip: " << senderZip << "\n"
		<< "\n" << "Recipient: " << recipientName << "\n"
		<< "Address: " << recipientaddress << "\n"
		<< "City: " << recipientCity << "\n"
		<< "State: " << recipientState << "\n"
		<< "Zip: " << recipientZip << "\n"
		<< "\nPackage Information:\n"
		<< "Weight(oz) : " << fixed << setprecision(2)
		<< weightInOunces << "\n"
		<< "Cost per ounce: $"
		<< fixed << setprecision(2)
		<< costPerOunce;


	return oss.str();
}