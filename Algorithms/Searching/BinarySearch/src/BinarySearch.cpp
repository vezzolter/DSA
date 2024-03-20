// Source file for binary search algorithm.
// by vezzolter
// March 17, 2024

#include "BinarySearch.h"


int binarySearch(int arr[], int left, int right, int target) {
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == target)
			return mid;

		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}