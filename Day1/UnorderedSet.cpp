#include "stdafx.h"
#include "UnorderedSet.h"
#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>


// Add words from a sentences to a hashset and then from a second sentence check if extra words were used
void UnorderedSet::createUnorderedSet()
{
	std::unordered_set<std::string> set;

	std::string firstString;
	std::string secondString;
	std::cout << "Enter first string: ";
	std::getline(std::cin, firstString);

	std::cout << "Enter second string to compare: ";
	std::getline(std::cin, secondString);

    std::stringstream stream1(firstString); // Insert the string into a stream
	std::stringstream stream2(secondString); // Insert the string into a stream
	std::string token;

	// insert first string items to the set
	while(std::getline(stream1, token, ' ')) {
		set.insert(token);
	}
	
	// Check for words from the second string in the hashset
	while(std::getline(stream2, token, ' ')) {
		if(set.find(token) == set.end())
		{
			std::cout << "There are new items in the second string";
			return;
		}
	}
	std::cout << "There are NO new items in the second string";
}	