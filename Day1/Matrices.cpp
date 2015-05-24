#include "stdafx.h"
#include <iostream>
#include <string>

static int** createMatrix(int &length, int &height);

static void traverseInSpiral();

// Takes in arguments -
/**
*	Takes in arguments -
*	matrix - The 2 dimensional matrix
*	length - length of the matrix
*	height - height of the matrix
*	std::pair <int, int> currentPosition - first->length coordinate, second->height coordinate
**/
static bool matrixRight(int** &matrix, const int &length, const int &height, std::pair <int, int> &currentPosition, int &value, const int endColumn);
static bool matrixLeft(int** &matrix, const int &length, const int &height, std::pair <int, int> &currentPosition, int &value, const int end);
static bool matrixUp(int** &matrix, const int &length, const int &height, std::pair <int, int> &currentPosition, int &value, const int end);
static bool matrixDown(int** &matrix, const int &length, const int &height, std::pair <int, int> &currentPosition, int &value, const int endRow);

static bool matrixUp(int** &matrix, const int &length, const int &height, std::pair <int, int> &currentPosition, int &value, const int startRow)
{
	if (currentPosition.second - 1 < startRow)
	{
		return false;
	}

	currentPosition.second--;
	value = matrix[currentPosition.second][currentPosition.first];

	return true;
}

static bool matrixDown(int** &matrix, const int &length, const int &height, std::pair <int, int> &currentPosition, int &value, const int endRow)
{
	if (currentPosition.second + 1 >= endRow)
	{
		return false;
	}

	currentPosition.second++;
	value = matrix[currentPosition.second][currentPosition.first];

	return true;
}

static bool matrixRight(int** &matrix, const int &length, const int &height, std::pair <int, int> &currentPosition, int &value, const int endColumn)
{
	if (currentPosition.first + 1 >= endColumn)
	{
		return false;
	}

	currentPosition.first++;
	value = matrix[currentPosition.second][currentPosition.first];
	
	return true;
}

static bool matrixLeft(int** &matrix, const int &length, const int &height, std::pair <int, int> &currentPosition, int &value, const int startColumn)
{
	if (currentPosition.first - 1 < startColumn)
	{
		return false;
	}

	currentPosition.first--;
	value = matrix[currentPosition.second][currentPosition.first];

	return true;
}

static int** createMatrix(int &length, int &height)
{
	length = 0; // Length of the matrix, ie. from left most to right most
	height = 0; // Height of the matrix, ie. from top to bottom
	
	std::string stringValue;
	std::string stringMatrix;
	while(true)
	{
	//	std::cout << "Enter row to enter in the Matrix, or enter 'n' to finish entering into the Matrix: ";
		std::cout << "Enter a row of numbers: ";
		std::getline(std::cin, stringValue);

		if (stringValue.compare("n") == 0)
		{
			// recieved n, end of matrix
			std::cout << "End of matrix\n";
			std::cout << stringMatrix;
			break;
		}
		else 
		{
			// Recieved a string of numbers, add that to the matrix
			// If received string is received for the first time, register the length
			if (length == 0)
			{
				length = stringValue.length();
			}

			// Check if length recieved is bigger or not
			if (stringValue.length() > length)
			{
				std::cout << "Sorry, matrix length exceeded, try again";
			}
			else 
			{
				// safety check passed, can add to matrix
				stringMatrix += stringValue;
				// Appending "Y" signifies end of row for the matrix
				stringMatrix += "Y";
				height++;
			}
		}
	}

	// parse stringMatrix to a matrix
	int** matrix = new int* [height];
	for (int row = 0; row < height; row++)
	{
		matrix[row] = new int[length];
	}

	// Fill in the array
	for(int row = 0; row<height; row++)
	{
		for(int column = 0; column<=length; column++)
		{
			if(stringMatrix.front() == 'Y')
			{
				stringMatrix.erase(0,1);
				continue;
			}
			matrix[row][column] = stringMatrix.front()-48; // Converting characters to ascii
			stringMatrix.erase(0,1);
		}
	}

	// Print the array
	std::cout << "\n";
	for(int row = 0; row<height; row++)
	{
		for(int column = 0; column<length; column++)
		{
			std::cout << matrix[row][column];
		}
		std::cout << "\n";
	}

	return matrix;

//	Rely on the class calling this function to deallocate memory
//	for(int i = 0; i < height; i++)
//	{
//		delete[] matrix[i];
//	}
//	delete[] matrix;
}