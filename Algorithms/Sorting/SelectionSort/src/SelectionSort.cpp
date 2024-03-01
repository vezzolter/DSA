// Source file for selection sort algorithm.
// by vezzolter
// February 28, 2024

#include "SelectionSort.h"

void selectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {

		int min = i;
		for (int j = i + 1; j < size; j++) {
			// Descending: arr[j] > arr[min]
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		// Can be optimized via swap
		if (min != i) {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}