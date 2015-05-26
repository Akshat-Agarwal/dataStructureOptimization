#include "stdafx.h"
#include <iostream>

static void intToString();
static std::string toStr(int number, int const base);
static std::string convertString(int number);

static int baseValue = 10;

/**
* Converts given integer values to Strings recursively. example 123 -> "123"
**/
static void intToString()
{
	int number;
	
	std::cout << "enter number to convert to string: ";
	std::cin >> number;
	std::cout << "enter base for the number: ";
	std::cin >> baseValue;

	std::cout << toStr(number, baseValue).c_str() << " ";
}

static std::string toStr(int number, int const base)
{
	if ( number < base )
	{
		return convertString(number);
	}
	else {
		return toStr(number/base, base).append(convertString(number%base));
	}
}

static std::string convertString(int number)
{
	if (number > baseValue)
	{
		return "number too big";
	}

	switch (number)
	{
	case 1:
		return "1";
		break;
	case 2:
		return "2";
		break;
	case 3:
		return "3";
		break;
	case 4:
		return "4";
		break;
	case 5:
		return "5";
		break;
	case 6:
		return "6";
		break;
	case 7:
		return "7";
		break;
	case 8:
		return "8";
		break;
	case 9:
		return "9";
		break;
	case 0:
		return "0";
		break;
	default:
		return "negative number";
		break;
	}
}