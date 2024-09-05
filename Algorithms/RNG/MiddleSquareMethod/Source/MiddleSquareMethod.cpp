// Source file for middle-square method
// by vezzolter
// March 21, 2024


#include <cmath>
#include "MiddleSquareMethod.h"


unsigned long long seed = 12345;
const int digits = 4;


unsigned long long middleSquareMethod() {
    unsigned long long squared = seed * seed;
    int power = static_cast<int>(pow(10, digits));
    int shift = digits / 2;
    unsigned long long randomNumber = (squared / static_cast<unsigned long long>(pow(10, shift))) % power;
    seed = randomNumber;
    return randomNumber;
}
