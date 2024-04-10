// Source file for Quicksort (Hoare Scheme).
// by vezzolter
// April 6, 2024

#include "Quicksort.h"


void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// Implements the median of 3 picking pivot strategy
// checks each position whether it is a middle value
int selectPivot(int* arr, int l, int r) {
	int m = l + (r - l) / 2;

	if ((arr[l] <= arr[m] && arr[m] <= arr[r]) || (arr[r] <= arr[m] && arr[m] <= arr[l]))
		return m;
	else if ((arr[m] <= arr[l] && arr[l] <= arr[r]) || (arr[r] <= arr[l] && arr[l] <= arr[m]))
		return l;
	else
		return r;
}

int partition(int* arr, int l, int r) {
	int p = selectPivot(arr, l, r); // median of 3
	
	swap(arr[p], arr[r]);
	p = r;

	for (; l < r; ) {
		for (; l <= r && arr[l] < arr[p]; l++);
		for (; r >= l && arr[r] >= arr[p]; r--);
		swap(arr[l], arr[r]);
	}

	swap(arr[l], arr[p]);
	p = l;

	return p;
}

void quicksort(int* arr, int l, int r) {
	if (l < r) {
		int p = partition(arr, l, r);
		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, r);
	}
}