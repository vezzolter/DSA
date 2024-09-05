// Header file for Quicksort (Hoare Scheme)
// by vezzolter
// April 6, 2024


#ifndef QUICKSORT_H
#define QUICKSORT_H


void swap(int& a, int& b);
int selectPivot(int* arr, int l, int r); // median of 3
int partition(int* arr, int l, int r);
void quicksort(int* arr, int l, int r);


#endif // QUICKSORT_H