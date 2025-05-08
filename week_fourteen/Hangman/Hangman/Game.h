/*
* script: Game.h
* action: This program contains the class
*         definition for the game hangman
* author: D.M
* date: 07MAY25
*/

#ifndef GAME_H
#define GAME_H

#include <string>


class Game {
public:

	// Default constructor
	Game(const std::string& selectedWord);

	// Copy constructor
	Game(const Game& other);

	// Declare methods
	void playGame();

private:

	// Declare private variables
	std::string word;
	std::string lettersGuessed;
	int incorrectGuesses;

	// Ensures the user does not go over the maximum number of incorrect guesses
	static const int maxIncorrect = 7;

	// Declare private methods

	// Clears the screen
	void clearScreen() const;

	// Draws the hangman
	void drawHangman() const;

	// Displays the word
	void displayWord() const;

	// Displays if the word is guessed or not
	bool isWordGuessed() const;

	// Converts the characters to lowercase
	char toLowerCase(char character) const;

};

#endif
