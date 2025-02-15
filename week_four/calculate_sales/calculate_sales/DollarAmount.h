/*
* script: DollarAmount.cpp
* action: Contains the dollar amount class
* author: D.M
* date: 15FEB25
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class DollarAmount {

public:

	// declare required constructor
	DollarAmount() : dollars(0), cents(0) {}

	// initialize constructor with the arguments dollars and cents
	DollarAmount(int d, int c) : dollars(d), cents(c) {

		// invoke function 
		convertCash();
	}

	// adds an additional dollar amount
	void add(const DollarAmount& other) {
		dollars += other.dollars;
		cents += other.cents;
		convertCash();
	}

	// declare function to convert dollars and cents to financial format
	void convertCash() {

		if (cents >= 100) {
			dollars += cents / 100;
			cents %= 100;
		}

		if (cents < 0) {
			dollars -= 1;
			cents += 100;
		}
	}

	// creates a dollar amount from total change
	static DollarAmount fromChange(int totalChange) {
		return DollarAmount(totalChange / 100, totalChange % 100);
	}

	// gets the total value in cents
	int getTotalChange() const {
		return dollars * 100 + cents;
	}


	// convert to a string format for output
	std::string print() const {
		std::ostringstream oss;
		oss << "$" << std::fixed << std::setprecision(2) << dollars + cents / 100.0 << std::endl;
		return oss.str();
	}
private: 
	// declare private variables
	int dollars;
	int cents;

};

