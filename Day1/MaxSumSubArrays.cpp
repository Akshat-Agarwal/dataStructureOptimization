#include "stdafx.h"
#include <iostream>

static void maxSum()
{
	int const ARRAY_SIZE = 8;
	int array [ARRAY_SIZE] = {1,-2,3,10,-4,7,2,-5};
	int currentSum = array[0];
	int maxSum = array[0];

	for(std::size_t i = 1; i<ARRAY_SIZE; i++)
	{
		if( currentSum+array[i] < array[i] )
		{
			// the new sum will be less than the the next item in the array
			// discard the sum 
			currentSum = array[i];
		}else {
			// Add the item to the current sum
			currentSum+=array[i];
			
			// check if maxSum needs to be updated
			maxSum = (maxSum>=currentSum) ? maxSum : currentSum;
		}
	}

	std::cout << "largest sum is: " << maxSum;
}