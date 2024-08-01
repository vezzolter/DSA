// Source file for Counting Sort
// by vezzolter
// July 25, 2024


#include "CountingSort.h"


int getMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    return maxVal;
}


void countingSort(int arr[], int size) {
    int maxVal = getMax(arr, size);

    int* count = new int[maxVal + 1];
    for (int i = 0; i <= maxVal; i++)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    delete[] count;
}
