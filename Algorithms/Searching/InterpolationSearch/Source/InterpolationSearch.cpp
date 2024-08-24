// Source file for Interpolation Search
// by vezzolter
// August 22, 2024


#include "InterpolationSearch.h"


int interpolationSearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Edge case: one element
        if (arr[low] == arr[high]) {
            if (arr[low] == target) { return low; } // target present
            else { return -1; }                     // target absent
        }

        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target) { return pos; }   // match, return
        if (arr[pos] < target) { low = pos + 1; } // greater, move low
        else { high = pos - 1; }                  // less, move high
            
    }

    return -1; // target absent
}