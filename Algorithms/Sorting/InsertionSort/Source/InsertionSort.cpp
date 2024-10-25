// Title:   Source file for Insertion Sort
// Authors: by vezzolter
// Date:    February 18, 2024
// ----------------------------------------------------------------------------


#include "InsertionSort.h"


void insertionSort(int arr[], int size) {
	for (int unsorted = 1; unsorted < size; unsorted++) {
		int current = arr[unsorted];

		int sorted = unsorted - 1;
		while (sorted >= 0 && arr[sorted] > current) {
			arr[sorted + 1] = arr[sorted];
			sorted = sorted - 1;
		}
		arr[sorted + 1] = current;
	}
}


