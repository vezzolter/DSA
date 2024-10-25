// Title:   Source file for Fibonacci (Recursive)
// Authors: by vezzolter
// Date:    January 24, 2024
// ----------------------------------------------------------------------------


#include "Fibonacci.h"

int fibonacci(int n) {
	if (n <= 1) { return n; }
	return fibonacci(n - 1) + fibonacci(n - 2);
}