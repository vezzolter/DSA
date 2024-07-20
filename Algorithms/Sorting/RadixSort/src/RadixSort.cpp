// Source file for Radix sort
// by vezzolter
// July 15, 2024


#include "RadixSort.h"


// Finds and returns the maximum value in an array
// Allows to determine the maximum number of digits
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n, int digitPos) {
    const int range = 10; // since digits are 0-9
    int* output = new int[n];
    int count[range] = { 0 };

    // Calculate count of occurrences of each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / digitPos) % 10;
        count[digit]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / digitPos) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted elements into the original array and clear it
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    delete[] output;
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Sorts the aray based on the current digit place, until all digits of max number
    for (int digitPos = 1; max / digitPos > 0; digitPos *= 10)
        countingSort(arr, n, digitPos);
}