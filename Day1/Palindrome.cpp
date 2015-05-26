#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include "reverseString.h"

static void palindrome();
static bool isPalindromeRecursive(std::string string);
static bool isPalindromeIterative(std::string string);

static void palindrome()
{
	std::string string;

	// Storing first string value
	std::cout<< "Enter string: ";
	std::getline(std::cin, string);

	// Sanitize the string by removing spaces and converting to lowercase
	string.erase(remove(string.begin(), string.end(), ' '), string.end());
	std::transform( string.begin(), string.end(), string.begin(), ::tolower );

	std::cout<<"Iteratively: "<<(isPalindromeIterative(string));
	std::cout<<"\nRecursively: "<<(isPalindromeRecursive(string));
}

static bool isPalindromeRecursive(std::string string)
{
	if(string.length() <= 1)
	{
		return true;
	}
	if(string.front() == string.back())
	{
		return isPalindromeRecursive(string.substr(1,string.length()-2));
	} else {
		return false;
	}
}

static bool isPalindromeIterative(std::string string)
{
	std::string stringReverse = reverseString::reverseIt(string);
	std::cout<<string<<"\t";
	std::cout<<stringReverse<<"\n";

	return stringReverse==string;
}