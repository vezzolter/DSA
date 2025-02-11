// Title:   Header file for Xorshift32
// Authors: by vezzolter
// Date:    February 3, 2025
// ----------------------------------------------------------------------------


#ifndef XORSHIFT32_H
#define XORSHIFT32_H


#include <cstdint>


class Xorshift32 {
private:
	uint32_t state;

public:
	explicit Xorshift32(uint32_t seed);
	uint32_t generate();
};

#endif // XORSHIFT32_H
