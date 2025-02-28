/*
* script: computer_assisted_instruction_v2.cpp
* action: This program that will help an elementary-school student learn multiplication.
*         This version adds additonal responses to encourage the student to stay focused.
* author: D.M
* date: 27FEB25
*/

#include <iostream>
#include <random>
#include <limits>

using namespace std;

// function prototypes
int questionGenerator();
string positiveResponse();
string incorrectResponse();



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

			// display a positive response to the user
			positiveResponse(); 

			// generate a new question
			correctAnswer = questionGenerator();
			cin >> userAnswer;
		}
		else {

			// display an incorrect response to the user
			incorrectResponse();
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

// This function generates a randomized positive response
string positiveResponse() {

	// declare pre-planned responses
	const string correctResponse[4] = { "Very good!", "Excellent!",
										"Nice work!", "Keep up the good work!"
	};

	// uses the default random number generator to generate pseudo-random numbers 1-4
	default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	uniform_int_distribution<int> randomNumber{ 1, 4 };

	// generate a random number
	int response = randomNumber(engine);

	// utilizing switch statement to display a random response
	switch (response) {
	case 1:
		cout << correctResponse[0] << "\n";
		break;
	case 2:
		cout << correctResponse[1] << "\n";
		break;
	case 3:
		cout << correctResponse[2] << "\n";
		break;
	case 4:
		cout << correctResponse[3] << "\n";
		break;
	default:
		cout << "Error: Invalid response number.\n";
		break;
	}
	// return the corresponding response
	return correctResponse[response - 1];
}

// This function generates a randomized incorrect response
string incorrectResponse() {
	// declare pre-planned responses
	const string incorrectResponse[4] = { "No. Please try again.", "Wrong. Try once more.",
											"Don't give up!", "No. Keep trying."
										};

	// uses the default random number generator to generate pseudo-random numbers 1-4
	default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	uniform_int_distribution<int> randomNumber{ 1, 4 };

	// generate a random number
	int response = randomNumber(engine);

	// utilizing switch statement to display a random response
	switch (response) {
	case 1:
		cout << incorrectResponse[0] << "\n";
		break;
	case 2:
		cout << incorrectResponse[1] << "\n";
		break;
	case 3:
		cout << incorrectResponse[2] << "\n";
		break;
	case 4:
		cout << incorrectResponse[3] << "\n";
		break;
	default:
		cout << "Error: Invalid response number.\n";
		break;
	}
	return incorrectResponse[response - 1];
}
