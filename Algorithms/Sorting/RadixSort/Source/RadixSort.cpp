// Title:   Source file for Radix Sort
// Authors: by vezzolter
// Date:    July 15, 2024
// ----------------------------------------------------------------------------


#include "RadixSort.h"


int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) { max = arr[i]; } 
    }

    return max;
}

void countingSort(int arr[], int n, int digitPos) {
    const int range = 10; // since digits are 0-9
    int* output = new int[n];
    int count[range] = { 0 };

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / digitPos) % 10;
        count[digit]++;
    }

    for (int i = 1; i < range; i++) { count[i] += count[i - 1]; }  

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / digitPos) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) { arr[i] = output[i]; }
    delete[] output;
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int digitPos = 1; max / digitPos > 0; digitPos *= 10) {
        countingSort(arr, n, digitPos);
    }
}