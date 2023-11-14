// Header file for tail-recursive implementation of the factorial function.
// by vezzolter
// November 13, 2023

#pragma once

// Takes non-negative number within specified range and returns its factorial
// The range limit is dictated by the size of data type in order to prevent overflow.
// e.g. int var can't contain the factorial of 13, the number is too big.
// Note: to prioritize simplicity and highligh algorithm itself, 'int' is picked as data type.
int factorialTail(int n);