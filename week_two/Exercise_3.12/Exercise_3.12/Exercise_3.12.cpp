/*
* script: Exercise_3.12.cpp
* action: This program demonstrates the date class functionality
* author: D.M
* date: 31JAN25
*/

#include <iostream>
#include "Date.h.cpp"

using namespace std;

int main()
{
	// initialize the date class
	Date testDate(7, 31, 2025);
	Date secondTestDate(1, 31, 2025);

	// display initial tesdate object
	cout << "The month is: " << testDate.getMonth() << endl;
	cout << "The day is: " << testDate.getDay() << endl;
	cout << "The year is: " << testDate.getYear() << endl;

	//display the formatted date
	testDate.displayDate();

	// displays secondTestDate
	cout << "\nDisplaying the second date\n";
	secondTestDate.displayDate();

	// manipulating secondTestDate
	cout << "\nChanging the second date to check validation";

	secondTestDate.setMonth(13); // entering invalid month
	secondTestDate.setDay(27);
	secondTestDate.setYear(2007);

	//display should show month defaulted to one
	secondTestDate.displayDate();


	return 0;
}


