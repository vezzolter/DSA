# &#128209; Table of Contents
- [💡 Overview](#-overview)
  - [Introduction](#introduction)
  - [Important Details](#important-details)
  - [Algorithm Steps](#algorithm-steps)
- [💻 Implementation](#-implementation)
  - [Design Decisions](#design-decisions)
  - [Complete Implementation](#complete-implementation)
  - [Detailed Walkthrough](#detailed-walkthrough)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
  - [Common Use Cases](#common-use-cases)
  - [Some Practical Problems](#some-practical-problems)
- [🕙 Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
The **Mersenne Twister** is a complex and highly efficient pseudorandom number generator (PRNG) known for its long period and excellent statistical properties. Its name comes from the fact that its period length is a Mersenne prime number, while «Twister» refers to the internal transformation step where bits of numbers are «twisted» through a series of bitwise operations to generate high-quality random numbers. Knowledge and understanding of it lay a solid foundation for algorithmic design and tackling more complex problem-solving strategies.
<p align="center"><img src="./Images/MersenneTwister.png"/></p>


## Introduction
The Mersenne Twister generates a sequence of pseudorandom numbers by maintaining an internal state array. This array holds intermediate values used to produce random numbers. The algorithm periodically updates the state array through a process called "twisting," which mixes bits from consecutive elements. The final numbers are produced through "tempering," which applies bit shifts and masks to ensure the numbers are well-distributed. Both twisting and tempering involve specific constants, carefully chosen from mathematical research, to control how the bits are manipulated and ensure the algorithm's long period and high-quality randomness.


## Important Details
1. **State Array Size** — fixed at $624$ integers because multiplying it by $32$-bit unsigned integers gives $19968$ bits, which is slightly more than the $19937$ bits required for the algorithm’s period. This ensures that the internal state can maintain enough bits to support the long period without introducing unnecessary overhead.
2. **Initialization Multiplier** — constant `f = 1812433253u` is used to spread the seed value effectively across all $624$ integers in the state array. The choice of `f` comes from research that optimizes how the seed influences the state, ensuring that the entire array is well-mixed from the start.
3. **Twisting Constants:**
   - `m = 397` — this value is chosen because it offsets the state array elements far enough during twisting to introduce a significant level of mixing while still maintaining a manageable computational cost.
   - `r = 31` — specifies how the state elements are split between upper and lower bits during mixing. By splitting at $31$ bits, the algorithm separates the more influential upper bits from the less significant lower bits, ensuring efficient manipulation while preserving enough randomness.
   - `a = 0x9908B0DF` — this value is chosen to XOR specific bits during twisting. It’s designed to invert certain bits in the state, based on tests that showed it produced better-distributed randomness. The specific pattern of this constant ensures optimal bit flipping without creating unwanted patterns.
4. **Tempering Constants:**
   - `u = 11` — this right shift removes the lower $11$ bits of the number, which tend to carry less useful randomness, improving the quality of the remaining bits.
   - `s = 7` — this left shift introduces high-order bits that help maintain variability in the higher bit positions.
   - `t = 15` and `l = 18` — these additional shifts were chosen based on statistical tests to further refine the bit structure after twisting, ensuring that even subtle bit-level variations are spread across the final output.
5. **Tempering Masks:**
   - `b = 0x9D2C5680` — this mask is applied to selectively retain or alter certain bits in the tempered output. The specific hexadecimal value was derived from research showing it helps create a more uniform distribution of random numbers, particularly by controlling how high-order bits are modified.
   - `c = 0xEFC60000` — this mask is applied to further tweak bits after the first mask, particularly targeting the mid-range bits. Its value is specifically chosen to balance out any potential bias introduced by the previous operations, ensuring the numbers remain well-distributed.


## Algorithm Steps
Currently in Progress...



# &#x1F4BB; Implementation
The program prompts the user to specify the number of random values to generate and define the range. It then uses the implemented PRNG to generate the specified amount of numbers and displays them as a numbered list.
<p align="center"><img src="./Images/Demonstration.png"/></p>


## Design Decisions
To prioritize simplicity and emphasize algorithm itself, several design decisions were made:
- Utilizing a library implementation of dynamic array `vector<>` to represent state array.
- Using fixed seed value to ensure reproducible results.
- Choosing range values that are easily interpretable by humans ($0-100$).
- Limiting the number of elements to a relatively small ($10$).
- Assuming valid input values from the user.
- Omitting certain optimizations to the algorithm.


## Complete Implementation
PRNG is implemented within the class `MersenneTwister`, which is declared in `MersenneTwister.h` header file and defined in `MersenneTwister.cpp` source file. This approach is adopted to ensure encapsulation, modularity and compilation efficiency. Examination of generated values is conducted within the `main()` function located in the `Main.cpp` file. Below you can find declaration of the class.

```cpp
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
```


## Detailed Walkthrough
Currently in Progress...



# &#128202; Analysis
Will be updated in future...

> **Note:** I'm currently considering how to best structure this section, as it involves several characteristics that I find intriguing to explore, such as period, distribution, predictability, and correlation.



# &#128221; Application
Currently in Progress...


## Common Use Cases
Currently in Progress...


## Some Practical Problems
Currently in Progress...


# &#x1F559; Origins
Currently in Progress...



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../../#-contacts).



# &#128591; Credits
&#127760; **Web-Resources:**  
- [Mersenne Twister](https://en.wikipedia.org/wiki/Mersenne_Twister)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)