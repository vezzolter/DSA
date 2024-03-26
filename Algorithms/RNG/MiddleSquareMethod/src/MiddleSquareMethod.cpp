// Source file for middle-square method algorithm.
// by vezzolter
// March 21, 2024

#include <cmath>
#include <iostream>
#include "MiddleSquareMethod.h"


int middleSquareMethod(int seed, int digits) {
    long long squared = static_cast<long long>(seed) * seed;

    // Extract the middle digits
    int power = 1;
    for (int i = 0; i < digits; ++i)
        power *= 10;
    int shift = (digits % 2 == 0) ? digits / 2 : (digits + 1) / 2;
    int randomNumber = (squared / static_cast<long long>(pow(10, shift - 1))) % power;

    return randomNumber;
}
