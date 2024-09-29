// Source file for Fibonacci
// by vezzolter
// January 24, 2024


#include "Fibonacci.h"

int fibonacci(int n) {
	if (n <= 1) { return n; } // Base case
	return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case

}