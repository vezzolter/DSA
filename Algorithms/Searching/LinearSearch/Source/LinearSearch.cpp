// Source file for Linear Search
// by vezzolter
// March 9, 2024


#include "LinearSearch.h"


int linearSearch(int arr[], int size, int target) {
	for (int i = 0; i < size; i++)
		if (arr[i] == target)
			return i;
	return -1;
}