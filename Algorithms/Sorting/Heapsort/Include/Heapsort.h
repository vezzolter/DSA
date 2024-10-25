// Title:   Header file for Heapsort
// Authors: by vezzolter
// Date:    June 1, 2024
// ----------------------------------------------------------------------------


#ifndef HEAPSORT_H
#define HEAPSORT_H


void swap(int& a, int& b);
void heapify(int arr[], int size, int i);
void buildMaxHeap(int arr[], int size);
void heapsort(int arr[], int size);


#endif // HEAPSORT_H