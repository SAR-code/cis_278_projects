/*
* script: computer_assisted_instruction.cpp
* action: This program helps an elementary student learn multiplication.
* author: D.M
* date: 27FEB25
*/


#include <iostream>
#include <random>
#include <limits>

using namespace std;

// function prototypes
int questionGenerator();



int main()
{
	// declare required variables
	int userAnswer{ 0 };
	int quit{ -1 };
	
	//display the equation and prompt user for an answer
	int correctAnswer = questionGenerator();
	cin >> userAnswer;

	while (userAnswer != quit) {

		// check if the user input is a number
		if (cin.fail()) {
			cin.clear(); // clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the line
			cout << "Invalid input. Please enter a number.\n";
			cin >> userAnswer;
		}
		
		// compares the user's answer to the correct answer
		if (userAnswer == correctAnswer) {
			cout << "Very good!\n";
			// generate a new question
			correctAnswer = questionGenerator();
			cin >> userAnswer;
		}
		else {
			cout << "No. Please try again.\n";
			cin >> userAnswer;
		}
	}


	return 0;
}

// This function generates a random number single digit number
int questionGenerator() {

	// uses the default random number generator to generate pseudo-random numbers 1-9
	default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	uniform_int_distribution<int> randomNumber{ 1, 9 };

	// generate two separete random numbers
	int firstNum = randomNumber(engine);
	int secondNum = randomNumber(engine);

	// display the question
	cout << "How much is " << firstNum << " times " << secondNum << "? (Enter -1 to quit)" << "\n";

	// declare a variable to store the user's correct answer
	int correctAnswer = firstNum * secondNum;

	return correctAnswer;

}



