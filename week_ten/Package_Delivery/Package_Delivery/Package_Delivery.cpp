/*
* script: Package_Delivery.cpp
* action: This is the main entry point for the Package_Delivery application.
*         This program demonstrates inheritance through a package delivery system.
* author: D.M
* date: 10APR25
*/

#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"

using namespace std;

int main()
{
   // test package
	Package package1("John Doe",
		"123 Elm St",
		"Springfield",
		"IL",
		"62701",
		"Jane Smith",
		"456 Oak St",
		"Chicago",
		"IL",
		"60601",
		10.0,
		2.5);

	// Display package details
	cout << "Package Details:" << endl;
	cout << "Sender: " << package1.getSenderName() << endl;
	cout << "Sender Address: " << package1.getSenderAddress() << endl;
	cout << "Sender City: " << package1.getSenderCity() << endl;
	cout << "Sender State: " << package1.getSenderState() << endl;
	cout << "Sender Zip: " << package1.getSenderZip() << endl;
	cout << "Recipient: " << package1.getRecipientName() << endl;
	cout << "Recipient Address: " << package1.getRecipientAddress() << endl;
	cout << "Recipient City: " << package1.getRecipientCity() << endl;
	cout << "Recipient State: " << package1.getRecipientState() << endl;
	cout << "Recipient Zip: " << package1.getRecipientZip() << endl;
	cout << "Weight (oz): " << package1.getWeightInOunces() << endl;
	cout << "Cost per ounce: $"
		<< package1.getCostPerOunce()
		<< endl;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "Total Cost: $"
		<< package1.calculateCost()
		<< endl;

	// test two day package
	TwoDayPackage twoDayPackage1("John Doe",
		"123 Elm St",
		"Springfield",
		"IL",
		"62701",
		"Jane Smith",
		"456 Oak St",
		"Chicago",
		"IL",
		"60601",
		10.0,
		2.5,
		5.0);

	// Display two day package details
	cout << "\nTwo Day Package Details:" << endl;
	cout << "Sender: " << twoDayPackage1.getSenderName() << endl;
	cout << "Sender Address: " << twoDayPackage1.getSenderAddress() << endl;
	cout << "Sender City: " << twoDayPackage1.getSenderCity() << endl;
	cout << "Sender State: " << twoDayPackage1.getSenderState() << endl;
	cout << "Sender Zip: " << twoDayPackage1.getSenderZip() << endl;
	cout << "Recipient: " << twoDayPackage1.getRecipientName() << endl;
	cout << "Recipient Address: " << twoDayPackage1.getRecipientAddress() << endl;
	cout << "Recipient City: " << twoDayPackage1.getRecipientCity() << endl;
	cout << "Recipient State: " << twoDayPackage1.getRecipientState() << endl;
	cout << "Recipient Zip: " << twoDayPackage1.getRecipientZip() << endl;
	cout << "Weight (oz): " << twoDayPackage1.getWeightInOunces() << endl;
	cout << "Cost per ounce: $"
		<< twoDayPackage1.getCostPerOunce()
		<< endl;
	cout << "Flat Fee: $"
		<< twoDayPackage1.getFlatFee()
		<< endl;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "Total Cost: $"
		<< twoDayPackage1.calculateCost()
		<< endl;



	return 0;
}


