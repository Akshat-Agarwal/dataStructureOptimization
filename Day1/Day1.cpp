// Day1.cpp : Defines the entry point for the console application.
// http://javarevisited.blogspot.ca/2015/01/top-20-string-coding-interview-question-programming-interview.html


#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <locale>
#include <vector>
#include <list>
#include <map>
#include "Permutations.cpp"

void duplicateCharacters();
void anagrams();
void firstUnique();
void reverseIteration();
void reverseRecursion();
std::string reverseIt(std::string str);
void containsOnlyNumericalValues();
void findLCM();
void findGCD();
int calculateGCD(int num1, int num2);
void levenshtein();

void _tmain()
{	
//	duplicateCharacters();
//	anagrams();
//	firstUnique();
//	reverseIteration();
//	reverseRecursion();
//	levenshtein();
//	containsOnlyNumericalValues();
//	findGCD();
//	findLCM();
	stringPermutations();
	return;
}

void findGCD() 
{
	int num1;
	int num2;

	std::cout << "Enter first number: ";
	std::cin >> num1;

	std::cout << "Enter second number: ";
	std::cin >> num2;

	std::cout << ((num1 > num2) ? calculateGCD(num1, num2) : calculateGCD(num2, num1));
}

int calculateGCD(int largeNum, int smallNum)
{
	return (largeNum % smallNum == 0) ? smallNum : calculateGCD(smallNum, largeNum % smallNum);
}

void findLCM()
{
	int int1;
	int int2;

	std::cout << "Enter first number: ";
	std::cin >> int1;

	std::cout << "Enter second number: ";
	std::cin >> int2;

	int gcd = (int1 > int2) ? calculateGCD(int1, int2) : calculateGCD(int2, int1);

	std::cout << "LCM is : " << (int1 * int2) / gcd;
	
}

// Check if a string contains only numerical digits
void containsOnlyNumericalValues() 
{
	std::string charString;

	std::cout << "Enter a string to check if it only contains numerical digits: ";
	std::getline(std::cin, charString);

	for( std::size_t i = 0; i < charString.length(); i++ )
	{
		// 0 maps to 48 in ascii
		// 9 maps to 57 in ascii
		// . maps to 46 in ascii
		// - maps to 45 in ascii
		// + maps to 43 in ascii
		// http://www.asciitable.com/
		if ( charString[i] < 43 || charString[i] >57 || charString[i] == 47)
		{
			std::cout << "String contains non numerical characters\n";
			return;
		}
	}

	std::cout << "String contains purely numerical characters\n";
}

// Objective based on http://en.wikipedia.org/wiki/Levenshtein_distance
// Find the Levenshteim distance between 2 strings
void levenshtein()
{
	// counter to keep track of levenshteim distance
	int counter = 0;
	// The orignal length of the shorter string.
	int orignalShortLength = 0;
	std::string strReceive1;
	std::string strReceive2;

	std::cout << "Enter first word ";
	std::getline(std::cin, strReceive1);

	std::cout<< "Enter second word ";
	std::getline(std::cin, strReceive2);

	// Convert string to lowercase
	std::transform( strReceive1.begin(), strReceive1.end(), strReceive1.begin(), ::tolower );
	std::transform( strReceive2.begin(), strReceive2.end(), strReceive2.begin(), ::tolower );

	int minLength = std::min( strReceive1.length(), strReceive2.length() );
	int maxLength = std::max( strReceive1.length(), strReceive2.length() );

	if( strReceive1.length() == strReceive2.length() )
	{
		// The 2 strings are of same length
		orignalShortLength = strReceive1.length();
	}
	else 
	{
		// Levenshteim distance is atleast the extra characters in one string 
		// as compared to the other
		counter = maxLength - minLength;
	}

	// Go through the common length of the 2 strings and check if 
	// characters are same
	for (std::size_t i = 0; i < minLength ; i++)
	{
		if( strReceive1[i] != strReceive2[i] )
		{
			counter++;
		}
	}

	std::cout << "\nlevenshtein distance is: " << counter << "\n";
}

// Reversing a string using iteration
void reverseIteration()
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

void reverseRecursion()
{
	std::string charString;

	std::cout << "Enter a string to reverse ";
	std::getline(std::cin, charString);

	std::cout << "And the reversed string is " << reverseIt(charString);
}

std::string reverseIt(std::string str)
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

// Print first non repeated character from String
void firstUnique()
{
	std::string charString;

	std::cout << "Enter string to search for first unique character: ";
	std::getline(std::cin, charString);

	// Convert string to lowercase
	std::transform( charString.begin(), charString.end(), charString.begin(), ::tolower );

	// Creating a map of type - 
	// Char Key - The letter in the string
	// Int Index - The index in which is was added to the map, so first item added will have index 0
	// Int Value - The number of repetitions of the key
	std::map<char, std::pair<int, int> > charMap;

	// Add items to hash map
	for (int i = 0, newAlphabetNum = 0; i < charString.length(); i++)
	{
		std::cout << i <<":" << charString[i] << "\n";
		if ( charMap.insert( std::pair<char, std::pair <int, int> >(charString[i], std::pair<int, int>(newAlphabetNum, 1)) )
			.second == false )
		{
			// Item wasnt inserted, it already exists in the map
			// Increase the count
			charMap.find(charString[i])->second.second = (charMap.find(charString[i])->second).second++;
		}else {
			// New alphabet added, increase counter count
			newAlphabetNum++;
		}
	}
	
	// Display the entire map
	for ( auto iter = charMap.begin(); iter != charMap.end(); iter++ )
	{
		std::cout << "item: " << iter->first << " at " << iter->second.first << " cout: " << iter->second.second << "\n";
	}

	// Get the first item with value 1
	for( int i = 0; i < charMap.size(); i++ )
	{
		// Go through the map in the order of the index
		for (auto iter = charMap.begin(); iter != charMap.end(); ++iter)
		{	
			// Find index
			if ( iter->second.first == i )
			{
				if (iter->second.second == 1)
				{
					std::cout << "First unique character is: " << iter->first;
					return;
				}
			}
		}
	}
}

void anagrams()
{
	std::string tempStr;

	// Storing first string value
	std::cout<< "Enter first string: ";
	std::getline(std::cin, tempStr);
	// Convert everything to lowercase
	std::transform( tempStr.begin(), tempStr.end(), tempStr.begin(), ::tolower );
	std::vector<char> firstString(tempStr.begin(), tempStr.end());
	
	// Storing second string value
	std::cout<< "Enter second string: ";
	std::getline(std::cin, tempStr);
	// Convert everything to lowercase
	std::transform( tempStr.begin(), tempStr.end(), tempStr.begin(), ::tolower );
	std::vector<char> secondString(tempStr.begin(), tempStr.end());

	// If sizes of 2 strings are different, they cannot be anagrams
	if(firstString.size() != secondString.size())
	{
		std::cout << "Not Anagrams";
		return;
	}

	// Sort both strings lexicographically (alphabetically)
	std::sort(firstString.begin(), firstString.end());
	std::sort(secondString.begin(), secondString.end());

	// Compare both sorted strings, if they are the same they are anagrams
	if (firstString == secondString)
	{
		std::cout << "They are Anagrams!";
	}else{
		std::cout << "Not Anagrams";
	}
}

/** http://java67.blogspot.sg/2014/03/how-to-find-duplicate-characters-in-String-Java-program.htmls
* Problem: Print duplicate characters in a string. So 'Java' must return 'a'
* and 'combination' must return 'ion'
**/
void duplicateCharacters()
{
	// Creating string tempStr and storing in tempStr
	std::string tempStr;
	std::getline(std::cin, tempStr);
	
	// Storing tempStr to inString
	std::vector<char> inString(tempStr.begin(), tempStr.end());

	std::cout << "The repeated characters are: ";
	
	// Creating a map
	std::map<char,int> stringMap;

	for(int i=0; i<inString.size(); i++){
		// Attempt to add a char to map
		if ( stringMap.insert( std::pair<char, int>(inString[i],1) ).second == false ){
			std::cout << inString[i] << ' ';
		}
	}

	std::cout << "\nsize of map: " << stringMap.size();

	return;
}