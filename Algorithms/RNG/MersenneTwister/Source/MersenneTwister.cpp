// Source file for Mersenne Twister
// by vezzolter
// September 7, 2024


#include "MersenneTwister.h"


MersenneTwister::MersenneTwister(uint32_t seed) { initialize(seed); }

void MersenneTwister::initialize(uint32_t seed) {
    stateArr.resize(n);
    stateArr[0] = seed;
    for (int i = 1; i < n; i++)
        stateArr[i] = f * (stateArr[i - 1] ^ (stateArr[i - 1] >> 30)) + i;
}

// Generates the next n numbers in the series
void MersenneTwister::twist() {
    const uint32_t lowMask = (1u << r) - 1;
    const uint32_t upMask = ~lowMask;

    for (int i = 0; i < n; i++) {
        uint32_t x = (stateArr[i] & upMask) + (stateArr[(i + 1) % n] & lowMask);
        uint32_t xA = x >> 1;
        if (x % 2 != 0) { xA ^= a; } // If the lowest bit is 1
        stateArr[i] = stateArr[(i + m) % n] ^ xA;
    }
    index = 0;
}

// Extracts a random number from the current state
uint32_t MersenneTwister::generate() {
    if (index >= n) { twist(); }

    uint32_t y = stateArr[index++];
    y ^= (y >> u);
    y ^= (y << s) & b;
    y ^= (y << t) & c;
    y ^= (y >> l);

    return y;
}