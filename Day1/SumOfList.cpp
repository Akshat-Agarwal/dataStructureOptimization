#include "stdafx.h"
#include <iostream>
#include <vector>

static void makeList();
static int listAdd(std::vector<int> numbers);


static void makeList()
{
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(6);
	numbers.push_back(7);
	numbers.push_back(8);
	numbers.push_back(9);
	numbers.push_back(10);

	std::cout<< listAdd(numbers);
}

static int listAdd(std::vector<int> numbers)
{
	std::cout<<"size " << numbers.size() << "\n";
	switch(numbers.size())
	{
		case 0:
			// no numbers in the list
			return 0;
		case 1:
			// just 1 item in the list, thats the sum
			return numbers.at(0);
		case 2:
			// 2 items in the list, add and return
			return numbers.at(0) + numbers.at(1);
		default:
			// size more than 2, recurse
			std::vector<int>::iterator i = numbers.begin() + 1;
			return numbers.at(0) + listAdd(std::vector<int>(i , numbers.end()));
	}
}