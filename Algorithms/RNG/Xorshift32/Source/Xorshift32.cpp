// Title:   Source file for Xorshift32
// Authors: by vezzolter
// Date:    February 3, 2025
// ----------------------------------------------------------------------------


#include "Xorshift32.h"


// Initializes the state with the given seed and ensures that its not a zero
Xorshift32::Xorshift32(uint32_t seed) {
	state = seed ? seed : 1;
}


// Generates the next pseudorandom number using the Xorshift32 transformations
uint32_t Xorshift32::generate() {
	state ^= state << 13;
	state ^= state >> 17;
	state ^= state << 5;

	return state;
}
