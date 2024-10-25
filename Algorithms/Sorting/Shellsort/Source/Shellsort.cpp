// Title:   Source file for Shellsort
// Authors: by vezzolter
// Date:    August 9, 2024
// ----------------------------------------------------------------------------


#include "Shellsort.h"


void shellsort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}