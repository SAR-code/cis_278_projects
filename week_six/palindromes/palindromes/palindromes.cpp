/*
* script: palindromes.cpp
* action: This program writes a recursive function that returns true
*         if a string is a palindrome and false otherwise.
* author: D.M
* date: 06MAR25
*/


#include <iostream>
#include <string>

using namespace std;

// function prototypes
bool testPalindrome(const string& str, int start, int end);
void isPalindrome(string str);

int main()
{
	// declare string variables to test if they are palindromes
	string testStringOne = "racecar";
	string testStringTwo = "hello";
	string testStringThree = "madam";

    // invoke the functions to determine if the strings are palindromes
	isPalindrome(testStringOne);
	isPalindrome(testStringTwo);
	isPalindrome(testStringThree);
	
	return 0;
}

// declare recursive function to test if a string is a palindrome
bool testPalindrome(const string& str, int start, int end) {

	// base case to determine if all of the characters have matched
	if (start >= end) {
		return true;

	} // base case to determine if the characters do not match
	else if (str[start] != str[end]) {
		return false;
	}

	// uses recursion to check the next set of characters
	return testPalindrome(str, start + 1, end - 1);
}

// declare a helper function to help test if a string is a palindrome
void isPalindrome(string str) {

	// invoking the testPalindrome function to check the string
	if (testPalindrome(str, 0, str.length() - 1)) {
		cout << str << " is a palindrome." << endl;
	}
	else {
		cout << str << " is not a palindrome." << endl;
	}

	

}
