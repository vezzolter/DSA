// Title:   Source file for Interpolation Search
// Authors: by vezzolter
// Date:    August 22, 2024
// ----------------------------------------------------------------------------


#include "InterpolationSearch.h"


int interpolationSearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (arr[low] == arr[high]) {
            if (arr[low] == target) { 
                return low;
            } else { 
                return -1;
            }                     
        }

        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target) { return pos; } 
        if (arr[pos] < target) { 
            low = pos + 1; 
        } else { 
            high = pos - 1; 
        }                  
    }

    return -1;
}