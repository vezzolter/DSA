// Source file for LCG algorithm
// by vezzolter
// August 28, 2024


#include "LCG.h"


const unsigned long long a = 1664525;          // Multiplier
const unsigned long long c = 1013904223;       // Increment
const unsigned long long m = 4294967296;       // Modulus (2^32)
unsigned long long seed = 12345;               // Initial seed

unsigned long long lcg() {
    seed = (a * seed + c) % m;
    return seed;
}