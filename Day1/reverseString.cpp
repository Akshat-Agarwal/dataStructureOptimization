#include "stdafx.h"
#include <iostream>
#include "reverseString.h"

// Reversing a string using iteration
void reverseString::reverseIteration()
{
	std::string charString;

	std::cout << "Enter a string to reverse ";
	std::getline(std::cin, charString);

	// Putting string into an array
	char *array = const_cast<char*>(charString.c_str());
	int arraySize = charString.size();

	// Swapping elements in the string
	for (std::size_t i = 0; i < arraySize/2; i++)
	{
		std::swap(*(array + i), *(array + arraySize - 1 - i));
	}

	std::cout << "\nand your reversed string is ";
	for(std::size_t i = 0; i<arraySize; i++)
	{
		std::cout<< *(array + i);
	}

}

void reverseString::reverseRecursion()
{
	std::string charString;

	std::cout << "Enter a string to reverse ";
	std::getline(std::cin, charString);

	std::cout << "And the reversed string is " << reverseIt(charString);
}

 std::string reverseString::reverseIt(std::string str)
{
	if(str.size() == 1)
	{
		return str;
	}

	// The one above is for better readability/understandability
	// However this way reduces iteration by 1 but uses a little extra
	// space to swap elements
/*  if(str.size() == 2)
	{
		char buffer = str[0];
		str[0] = str[1];
		str[1] = buffer;
		return str;
	}
*/

	// Substring() takes 2 parameters, starting position and length (second parameter is length and not ending position)
	std::string smallString = str.substr(0, str.size()-1);

	return str[str.size()-1]+reverseIt(smallString);
}