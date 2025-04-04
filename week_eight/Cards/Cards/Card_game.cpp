/*
* script: Card_game.cpp
* action: This program shuffles and deals cards from a standard deck of 52 playing cards.
* author: D.M
* date: 29MAR25
*/

#include <iostream>
#include <iomanip>
#include "DeckOfCards.h"
#include "Card.h"

using namespace std;
using std::setw;
using std::left;


// Function prototype for starting the game
void startGame();

int main()
{
	// invokes the function
	startGame();

	return 0;
}

// function that starts the came by creating a deck of cards, shuffling it, and dealing the cards
void startGame() {

	DeckOfCards deck; 
	deck.shuffleCards();


	// for loop to deal 52 cards from the deck

	for (int idx = 0; idx < 52; ++idx) {
		// aligns the columns neatly in the output
		cout << left;
		cout << "  " << setw(20) << deck.dealCard().toString() << "  ";
		if ((idx + 1) % 4 == 0) {
			// Print a new line after every 4 cards to format the output
			cout << "\n";
		}

	}
}


