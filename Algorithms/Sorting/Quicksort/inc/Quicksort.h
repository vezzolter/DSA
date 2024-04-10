// Header file for Quicksort (Hoare Scheme)
// by vezzolter
// April 6, 2024

#pragma once

void swap(int& a, int& b);
int selectPivot(int* arr, int l, int r); // median of 3
int partition(int* arr, int l, int r);
void quicksort(int* arr, int l, int r);
