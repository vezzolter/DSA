// Source file for Counting Sort
// by vezzolter
// July 25, 2024


#include "CountingSort.h"


void countingSort(int arr[], int size) {
    // Find the maximum value in the array
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Initialize count array with zeros
    int* count = new int[maxVal + 1];
    for (int i = 0; i <= maxVal; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each value
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // Write the sorted values back into the original array
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    // Free the allocated memory for the count array
    delete[] count;
}
