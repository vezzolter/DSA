// Source file for Merge Sort
// by vezzolter
// March 31, 2024

#include "MergeSort.h"


void merge(int* arr, const int left, const int mid, const int right) {
	int arrLeftSize = mid - left + 1;
	int arrRightSize = right - mid;
	int* arrLeft = new int[arrLeftSize];
	int* arrRight = new int[arrRightSize];
	for (int i = 0; i < arrLeftSize; i++)
		arrLeft[i] = arr[left + i]; // arr[begin...mid]
	for (int i = 0; i < arrRightSize; i++)
		arrRight[i] = arr[mid + 1 + i]; // arr[mid+1...end]

	int arrLeftIndex = 0;
	int arrRightIndex = 0;
	int arrIndex = left;
	for (; arrLeftIndex < arrLeftSize && arrRightIndex < arrRightSize; ) {
		if (arrLeft[arrLeftIndex] <= arrRight[arrRightIndex]) {
			arr[arrIndex] = arrLeft[arrLeftIndex];
			arrLeftIndex++;
		}
		else {
			arr[arrIndex] = arrRight[arrRightIndex];
			arrRightIndex++;
		}
		arrIndex++;
	}

	for (; arrLeftIndex < arrLeftSize;) {
		arr[arrIndex] = arrLeft[arrLeftIndex];
		arrLeftIndex++;
		arrIndex++;
	}

	for (; arrRightIndex < arrRightSize;) {
		arr[arrIndex] = arrRight[arrRightIndex];
		arrRightIndex++;
		arrIndex++;
	}

	delete[] arrLeft;
	delete[] arrRight;
}

void mergeSort(int* arr, const int left, const int right) {
	if (left >= right)
		return;

	int mid = left + (right - left) / 2; 
	mergeSort(arr, left, mid); // arr[begin...mid]
	mergeSort(arr, mid + 1, right); // arr[mid+1...end]
	merge(arr, left, mid, right);
}
