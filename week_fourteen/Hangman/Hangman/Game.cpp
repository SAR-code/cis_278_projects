/*
* script: Game.cpp
* action: This program contains the implementation
*         of the class definition for the game hangman
* author: D.M
* date: 07MAY25
*/

#include "Game.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

// Sets the structure for the hangman stages
const std::string hangmanStages[] = {
"",
    "  O",
    "  O\n  |",
    "  O\n /|",
    "  O\n /|\\",
    "  O\n /|\\\n  |",
    "  O\n /|\\\n  |\n /",
    "  O\n /|\\\n  |\n / \\"
};


// Default constructor for the Game class
Game::Game(const std::string& selectedWord)
{
    // Defines the word to be guessed
    word = selectedWord;
    lettersGuessed = "";

    // sets the number of incorrect guesses to 0
    incorrectGuesses = 0;
}


// Copy constructor for the Game class
Game::Game(const Game& other)
{
    // Copies the word to be guessed
    word = other.word;
    lettersGuessed = other.lettersGuessed;
    incorrectGuesses = other.incorrectGuesses;

}

// Method to clear the screen
void Game::clearScreen() const
{
    // Clears the screen
	cout << "\033[2J\033[1;1H";
}


// Method to convert characters to lowercase
char Game::toLowerCase(char character) const
{
    // Converts the characters into lowercase
    return static_cast<char>(tolower(static_cast<unsigned char>(character)));
}


// Method to draw the hangman
void Game::drawHangman() const
{
    // Draws the hangman based on the number of incorrect guesses
    cout << "\nIncorrect guesses: " << incorrectGuesses << "/" << maxIncorrect << endl;
    cout << hangmanStages[incorrectGuesses] << endl;

}


// Method to display the word
void Game::displayWord() const
{

    // Displays the word with guessed letters and X for unknown letters
    cout << "Guess the word: ";

    for (char character : word)
    {
        if (lettersGuessed.find(character) != string::npos)
        {
            cout << character;
        }
        else {
            cout << "X";
        }
    }

    cout << "\n";
    
}


// Method to check if the word is guessed
bool Game::isWordGuessed() const
{
    // Verifies if the word has been guessed
    for (char character : word)
    {
        if (lettersGuessed.find(character) == string::npos)
        {
            return false;
        }
    }
}

// Method to start the game
void Game::playGame()
{

    // Checks if incorrect guesses are less than max guesses
    while (incorrectGuesses < maxIncorrect) {
        // Clears the screen
        clearScreen();

        // Draws the hangman
        drawHangman();

        // Displays the word
        displayWord();

        // Prompts the user to guess a letter
        cout << "Guessed letters: " << lettersGuessed << endl;
        cout << "Enter a letter: ";
        char userGuess;
        cin >> userGuess;

        // Converts the input to lowercase
        userGuess = toLowerCase(userGuess);

        // Checks if the letter has already been guessed
        if (lettersGuessed.find(userGuess) != string::npos)
        {
            // Diplays that the letter has already been guessed
            cout << "Letter already guessed, Try again!" << endl;
            continue;
        }

        // Adds the letter to the guessed letters
		lettersGuessed += userGuess;

        // Checks if the letter is in the word
        if (word.find(userGuess) != string::npos)
        {
            cout << "Good guess!" << endl;
        }
        else {
            cout << "Incorrect guess!" << endl;
			incorrectGuesses++;
        }

        // Checks to see if the word has been guessed
        if (isWordGuessed()) {
             // Resets the game and congratulates the user
            clearScreen();
            drawHangman();
            displayWord();
            cout << "\nCongratulations! You guessed the word: " << word << endl;
            return;
        }
    }

    // If the user runs out of guesses, the game ends
    clearScreen();
    drawHangman();
    cout << "Game over! The word was: " << word << endl;

}


