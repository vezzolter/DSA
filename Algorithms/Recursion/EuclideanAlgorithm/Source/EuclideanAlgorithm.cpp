// Title:   Source file for Euclidean Algorithm (Recursive)
// Authors: by vezzolter
// Date:    January 28, 2025
// ----------------------------------------------------------------------------


#include "EuclideanAlgorithm.h"


int euclidean(int a, int b) {
	if (b == 0) { return a; }
	return euclidean(b, a % b);
}