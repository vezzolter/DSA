// Title:   Source file Factorial (Recursive)
// Authors: by vezzolter
// Date:    November 13, 2023
// ----------------------------------------------------------------------------


#include "Factorial.h"


int factorial(int n) {
	if (n == 0 || n == 1) { return 1; }
	return n * factorial(n - 1);
}