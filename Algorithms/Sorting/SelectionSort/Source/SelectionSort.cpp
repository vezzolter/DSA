// Source file for Selection Sort
// by vezzolter
// February 28, 2024


#include "SelectionSort.h"


void selectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {

		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		if (min != i) {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}