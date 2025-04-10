/*
* script: Package.h
* action: Contains the base package class
* author: D.M
* date: 10APR25
*/

#include <iostream>
#include <string>

#ifndef PACKAGE_H
#define PACKAGE_H

class Package {

public:

	// Default constructor for package class
	explicit Package(const std::string&, 
					 const std::string&,
					 const std::string&,
					 const std::string&,
					 const std::string&, 
					 const std::string&,
					 const std::string&,
					 const std::string&,
					 const std::string&,
					 const std::string&,
					 double = 0.0,
					 double = 0.0
					);
	
	// Copy constructor
	Package(const Package& other);

	// Detructor
	~Package();

	// Methods for the Package class

	// Setters and getters for the names
	void setSenderName(const std::string&);
	std::string getSenderName() const;

	void setRecipientName(const std::string&);
	std::string getRecipientName() const;


	// Setters and getters for the addresses
	void setSenderAddress(const std::string&);
	std::string getSenderAddress() const;

	void setRecipientAddress(const std::string&);
	std::string getRecipientAddress() const;


	// Setters and getters for the cities
	void setSenderCity(const std::string&);
	std::string getSenderCity() const;

	void setRecipientCity(const std::string&);
	std::string getRecipientCity() const;


	// Setters and getters for the states
	void setSenderState(const std::string&);
	std::string getSenderState() const;

	void setRecipientState(const std::string&);
	std::string getRecipientState() const;

	
	// Setters and getters for the zip codes
	void setSenderZip(const std::string&);
	std::string getSenderZip() const;

	void setRecipientZip(const std::string&);
	std::string getRecipientZip() const;

	// Setters and getters for the weight and cost
	void setWeightInOunces(double);
	double getWeightInOunces() const;

	void setCostPerOunce(double);
	double getCostPerOunce() const;

	// Method to calculate the total cost of the package
	double calculateCost() const;

	// String representation of the package
	std::string toString() const;



private:

	// declare private member variables

	// variables for sender information
	std::string senderName;
	std::string senderaddress;
	std::string senderCity;
	std::string senderState;
	std::string senderZip;

	// variables for recipient information
	std::string recipientName;
	std::string recipientaddress;
	std::string recipientCity;
	std::string recipientState;
	std::string recipientZip;

	// variables for package information
	double weightInOunces;
	double costPerOunce;

};

#endif