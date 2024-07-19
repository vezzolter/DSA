// Source file for Radix sort
// by vezzolter
// July 15, 2024


#include "RadixSort.h"


int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int place) {
    const int range = 10; // For digits 0-9
    int* output = new int[n];
    int count[range] = { 0 };

    // Calculate count of occurrences of each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // place is 10^i where i is the current digit number
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(arr, n, place);
    }
}