/*
* script: maze_traversal.cpp
* action: This program is a twodimensional array that represents a maze. Create a 
*         program that will traverse the maze. The program should be able to find
* 	      the exit from the maze using recursive functions.
* author: D.M
* date: 06MAR2025
*/

#include <iostream>
#include <vector>

using namespace std;

// declare global variables for key movements

int xAxis[] = { -1, 0, 1, 0 };		// row movement
int yAxis[] = { 0, 1, 0, -1 };		// column movement

// Function prototype
vector<vector<char>> createMaze(int startX, int startY);
void loadMaze(const vector<vector<char>>& maze);
bool checkMovement(const vector<vector<char>>& maze, int rows, int cols);
bool traverseMaze(vector<vector<char>>& maze, int rows, int cols);



int main()
{
	// declare variable to represent the starting point of the maze
	int startRow = 10;
	int startCol = 1;

	
	vector<vector<char>> mazeField = createMaze(startRow, startCol);
	traverseMaze(mazeField, startRow, startCol);

	return 0;
}

// Function to create the required maze

vector<vector<char>> createMaze(int startX, int startY)
{
	// Create a 2D array that represents the maze
	vector<vector<char>> maze = {
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
		{'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
		{'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
		{'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
		{'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
		
	};

	maze[startX][startY] = 'X';


	return maze;

}

// declare function to load the maze

void loadMaze(const vector<vector<char>>& maze)
{
	
	// declare a for loop to iterate through the maze then display

	for (int  i = 0; i < maze.size(); i++)
	{
		for (int  j = 0; j < maze[i].size(); j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

// Function to check if the movement is within the maze and valid
bool checkMovement(const vector<vector<char>>& maze, int rows, int cols) {

	// check if the movement is within the maze
	if (rows >= 0 && rows < maze.size() && cols >= 0 && cols < maze[0].size() && maze[rows][cols] == '.')
	{
		return true;
	}
	return false;
}

// Function to traverse the maze using recursion

bool traverseMaze(vector<vector<char>>& maze, int rows, int cols) {

	// base case for locating the exit
	if (rows == maze.size() - 1 && cols == maze[0].size() - 1)
	{
		maze[rows][cols] = 'X';
		loadMaze(maze);

		return true;
	}

	// attempts movement in all directions
	for (int i = 0; i < 4; i++) {

		// updates each movement
		int newRow = rows + xAxis[i];
		int newCol = cols + yAxis[i];

		if (checkMovement(maze, newRow, newCol)) {

			maze[newRow][newCol] = 'X';
			loadMaze(maze);

			// traverses maze recursively

			if (traverseMaze(maze, newRow, newCol)) {
				return true;
			}

			// resets the movement if it is invalid
			maze[newRow][newCol] = '.';
	
		}

		
	}

	return false;
}