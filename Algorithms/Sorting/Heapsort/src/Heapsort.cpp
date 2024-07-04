// Source file for Heapsort
// by vezzolter
// June 1, 2024

#include<algorithm>
#include "Heapsort.h"


void heapify(int arr[], int size, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

void buildMaxHeap(int arr[], int size) {
    // Index of the last non-leaf node
    int startIdx = (size / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

void heapsort(int arr[], int size) {
    // Build heap (rearrange array)
    buildMaxHeap(arr, size);

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}