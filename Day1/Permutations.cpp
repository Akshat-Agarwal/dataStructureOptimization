#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <locale>
#include <vector>
#include <list>
#include <map>

static void stringPermutations();
static void permute(std::string& string, int startPosition);


// This function takes in a string and outputs all the valid permutations of that string
// using recursion
static void stringPermutations()
{
	// Get the string to permute
	std::string string;

	std::cout<< "Enter first string: ";
	std::getline(std::cin, string);

	permute(string, 0);
}

static void permute(std::string& string, int startPosition)
{
	if (startPosition == string.size())
	{
		std::cout << string << "\n";
	}
	else 
	{
		for (std::size_t index = startPosition; index < string.size(); index++)
		{
			// Swap to get a permutation
			std::swap(string[index], string[startPosition]);
			
			permute(string, (startPosition+1));
			
			// Revert back to orignal position for next iteration
			std::swap(string[index], string[startPosition]);
		}
	}
}