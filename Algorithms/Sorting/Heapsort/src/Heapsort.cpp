// Source file for Heapsort
// by vezzolter
// June 1, 2024

#include "Heapsort.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int size, int i) {
    int largest = i;       // initialize largest as root
    int left = 2 * i + 1;  // left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }   

    // If right child is larger than largest so far
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
        
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest); // recursively heapify the affected sub-tree
    }
}

void buildMaxHeap(int arr[], int size) {
    int startIdx = (size / 2) - 1; // index of the last non-leaf node

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

void heapsort(int arr[], int size) {
    buildMaxHeap(arr, size);

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // move current root to end
        heapify(arr, i, 0); // call max heapify on the reduced heap
    }
}