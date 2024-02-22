// Source file for insertion sort algorithm.
// by vezzolter
// February 18, 2024

#include "InsertionSort.h"


void insertionSort(int arr[], int size) {
	for (int unsorted = 1; unsorted < size; unsorted++) {
		int current = arr[unsorted];

		int sorted = unsorted - 1; // start from the end of sorted part
		// For descending order: arr[sorted] < current
		while (sorted >= 0 && arr[sorted] > current) {
			arr[sorted + 1] = arr[sorted]; // can be optimized via swap
			sorted = sorted - 1;
		}
		arr[sorted + 1] = current;
	}
}


