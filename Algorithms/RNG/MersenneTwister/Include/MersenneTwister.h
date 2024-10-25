// Title:   Header file for Mersenne Twister
// Authors: by vezzolter
// Date:    September 7, 2024
// ----------------------------------------------------------------------------


#ifndef MERSENNETWISTER_H
#define MERSENNETWISTER_H


#include <cstdint>
#include <vector>


class MersenneTwister {
private:
    static const int n = 624;                 // Length of the state array (number of 32-bit values in the internal state)
    static const int m = 397;                 // Middle word; offset for mixing the state in the "twist" step
    static const int r = 31;                  // Number of bits used to separate the lower and upper parts of the state
    static const uint32_t a = 0x9908B0DF;     // Constant used in the twisting transformation
    static const int u = 11;                  // Shift used during the tempering process (right shift)
    static const int s = 7;                   // Shift used during the tempering process (left shift)
    static const int t = 15;                  // Another shift used in tempering (left shift)
    static const int l = 18;                  // Final right shift in the tempering process
    static const uint32_t b = 0x9D2C5680;     // Mask used in the tempering process for bitwise AND
    static const uint32_t c = 0xEFC60000;     // Another mask used in the tempering process
    static const uint32_t f = 1812433253u;    // Multiplier used during the initialization of the state array

    std::vector<uint32_t> stateArr;
    int index = n + 1;

    void initialize(uint32_t seed);
    void twist();

public:
    MersenneTwister(uint32_t seed = 5489u);  
    uint32_t generate();
};


#endif // MERSENNETWISTER_H
