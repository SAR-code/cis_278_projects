/*
* script: TortoiseHare.cpp
* action: This program recreates the classic race of the tortoise and the hare.
* author: D.M
* date: 13MAR25
*/

#include <iostream>
#include <random>
#include <ctime>


using namespace std;

// uses random number generator to geberate a number between 1 and 10
default_random_engine engine{ static_cast<unsigned int>(time(0)) };
uniform_int_distribution<int> randomNumber{ 1, 10 };

// Function prototypes
void displayRace(int t_position, int h_position);
void moveTortoise(int* position);
void moveHare(int* position);
void startRace();


int main()
{
	// invoke required functions to start program
	startRace();

    return 0;
}

// declare function to display the race

void displayRace(int t_position, int h_position)
{
	// display the position of the tortoise and hare
	for (int i = 1; i <= 70; i++)
	{
		if (i == t_position && i == h_position)
			cout << "OUCH!";
		else if (i == t_position)
			cout << "T";
		else if (i == h_position)
			cout << "H";
		else
			cout << "-";
	}

	cout << endl;
}

	// declare function that moves the tortoise

void moveTortoise(int* position) {

	// assigns random number to the movement
	int t_move = randomNumber(engine);

	if (t_move <= 5) {
		// The move type Fast Plod is used
		*position += 3;
	}
	else if (t_move <= 7) {
		// The move type Slip is used
		*position -= 6;
	}
	else {
		// the move type Slow Plod is used
		*position += 1;
	}

	// keeps the tortoise on the field

	if (*position < 1) {

		*position = 1;
	}

	if (*position > 70) {

		*position = 70;
	}
}

void moveHare(int* position) {


	// assigns random number to the movement
	int h_move = randomNumber(engine);

	if (h_move <= 2) {
		// sleep, no position change
		//*position += 0;
	}
	else if (h_move <= 4) {

		// move type Big Hop
		*position += 9;
	}
	else if (h_move == 5) {

		// move type Big slip
		*position -= 12;
	}
	else if (h_move <= 8) {
		// move type small hop
		*position += 1;
	}
	else {
		*position -= 2;
	}

	// keeps the hare on the field

	if (*position < 1) {

		*position = 1;
	}

	if (*position > 70) {

		*position = 70;
	}


}

// declare a function to start the race

void startRace() {

	// declare required variables for the race

	int tortoisePosition = 1;
	int harePosition = 1;
	int timer = 0;

	// displays the start of the race

	cout << "BANG !!!!\nAND THEY'RE OFF!!!!\n";

	// declare while loop to invoke the required functions
	while (tortoisePosition < 70 && harePosition < 70) {

		moveTortoise(&tortoisePosition);
		moveHare(&harePosition);
		displayRace(tortoisePosition, harePosition);
		timer++;
	}

	// displays the results based off the outcome

	if (tortoisePosition >= 70 && harePosition >= 70) {
		cout << "It's a tie!\n";
	}
	else if (tortoisePosition >= 70) {

		cout << "TORTOISE WINS!!! YAY!!!\n";

	}
	else {
		cout << "Hare wins. Yuch.\n";
	}

	cout << "Race finished in " << timer << " seconds." << endl;
}


