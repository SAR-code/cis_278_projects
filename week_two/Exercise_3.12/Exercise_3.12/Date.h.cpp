/*
* script: Date.h.cpp
* action: Contains the date class
* author: D.M
* date: 31JAN25
*/

#include <iostream>
class Date {

public:

	// constructor for date class
	explicit Date(int monthInput, int dayInput, int yearInput)
		: month{ monthInput }, day{ dayInput }, year{ yearInput } {
		
		if (monthInput > 12 || monthInput < 0) {
			month = 1;
		}
		else {
			month = monthInput;
		}
	}

	// sets and gets the month data input
	void setMonth(int monthInput) {
		
		// statement containing logic to determine month input defaults to 1 
		// if incorrect input is detected

		if (monthInput > 12 || monthInput < 0) {
			month = 1;
		}
		else {
			month = monthInput;
		}
	}

	int getMonth() const {
		return month;
	}

	// sets and gets the day data input
	void setDay(int dayInput) {
		day = dayInput;
	}

	int getDay() const {
		return day;
	}

	// sets and gets the year data input
	void setYear(int yearInput) {
		year = yearInput;
	}

	int getYear() const {
		return year;
	}

	// member function to display the date in a specific format
	void displayDate() const {
		std::cout << "\n" << month << "/" << day << "/" << year << "\n";
	}

private:
	int month;
	int day;
	int year;
};