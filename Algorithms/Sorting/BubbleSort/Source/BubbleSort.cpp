// Source file for bubble sort algorithm.
// by vezzolter
// February 25, 2024

#include "BubbleSort.h"

void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		bool swapped = false; 

		for (int j = 0; j < size - i - 1; j++) {
			// For descending order: arr[j] < arr[j + 1]
			if (arr[j] > arr[j + 1]) {
				// Can be optimized via swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}
	}
}