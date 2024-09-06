# &#128209; Table of Contents
- [💡 Overview](#-overview)
  - [Essential Terminology](#essential-terminology)
- [💻 Implementation](#-implementation)
  - [How to Implement](#how-to-implement)
  - [Pitfalls and Optimizations](#pitfalls-and-optimizations)
  - [Implemented Algorithms](#implemented-algorithms)
- [📊 Analysis](#-analysis)
  - [How to Analyze](#how-to-analyze)
  - [Trade-Offs](#trade-offs)
  - [Alternatives](#alternatives)
- [📝 Application](#-application)
  - [Common Use Cases](#common-use-cases)
  - [Some Practical Problems](#some-practical-problems)
- [🕙 Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
**Random Number Generation** is a key operation in computer science, used to produce numbers that are **perceived** as random. It is crucial to understand the concept to ensure that the generated numbers exhibit the desired statistical properties and behaviors in various algorithms for all manner of applications.
<p align="center"><img src="./Images/RNG.png"/></p>



## Essential Terminology
- **Randomness** — typically refers to the quality of unpredictability or lack of tracing pattern.
   - **Random Numbers** — is a sequence of numbers, where each number was obtained by chance, having nothing to do with other number of the sequence.
   - **RNG (Random Number Generator)** — is a computational algorithm that produces sequences of numbers that exhibit randomness.
- **Seed** — is an initial value used to initialize a PRNG. By setting a specific seed, it is possible to recreate the same sequence of random numbers, which can be useful for debugging or testing.
- **Period** — is a number of unique values in the sequence before it starts to repeat, while for PRNG it is finite, for TRNG it is effectively infinite.
- **Entropy** — is a degree of unpredictability of a sequence of data collected from hardware sources; i.e. the greater it is, the less predictable sequence is.
  - **Entropy Source** — is a physical or computational process that provides random or unpredictable data; i.e. basically the source from where the entropy is collected, such as electronic noise.
- **Distribution** — is a description of how values  are distributed.
  - **Uniform Distribution** — where every value within a given range has the same probability of occurring.
  - **Normal (Gaussian/Bell) Distribution** — where most values cluster around the mean, with fewer values farther from the mean.
  - **Binomial Distribution** — where the distribution describes the number of successes in a fixed number of independent trials, each with the same probability of success.



# &#x1F4BB; Implementation
When implementing a RNG, it's essential to understand the fundamental techniques that drive its behavior and ensure its correct functionality. Additionally, recognizing the critical pitfalls and potential optimizations allows you to refine the implementation, making it more efficient and robust for various scenarios.


## How to Implement
The choice of RNG depends on the application's specific needs, including the balance between speed, randomness quality, and security. Generally, there are two main categories of generators:

**PRNG (Pseudorandom Number Generator)** — is a deterministic type of RNG that generates numbers that only appears to be random. It is called that way because given the same starting conditions, it yields the same result.
<p align="center"><img src="./Images/PRNG.png"/></p>

**TRNG (True Random Number Generator)** — is a non-deterministic type of RNG that generates truly random numbers. It involves exploiting inherently unpredictable physical processes related to hardware (e.g. quantum processes, radioactive decay, electronic noise, optical noise, etc).
<p align="center"><img src="./Images/TRNG.png"/></p>


## Pitfalls and Optimizations
Currently in Progress...


## Implemented Algorithms
Discussing practical implementations, it's evident that well-established and widely recognized solutions already exist. In the context of C++, the `<random>` library provides access to robust RNG implementations, such as Mersenne Twister, Linear Congruential Generator and others. It's commonly recommended to rely on these proven implementations rather than reinventing the wheel. However, within the scope of this section, we'll take a closer look at simplified versions of popular RNG. This will help us gain a deeper understanding of the core mechanisms and design principles behind them.
  - [Middle-Square Method](https://github.com/vezzolter/DSA/tree/main/Algorithms/RNG/MiddleSquareMethod) ✅
  - [LCG (Linear Conguential Generator)](https://github.com/vezzolter/DSA/tree/main/Algorithms/RNG/LCG)  ✅
  - Mersenne Twister
  - Xorshift
  - PCG (Permuted Congruential Generator) (?)
  - Xoshiro128 (?)



# &#128202; Analysis
Understanding how to analyze a concept is crucial for identifying its key characteristics and evaluating its performance across different scenarios. Additionally, examining the trade-offs allows you to understand what you gain and what you give up when applying the concept. Finally, considering alternatives helps you determine when the concept is the best choice and when other approaches might be more appropriate.


## How to Analyze
Currently in Progress...


## Trade-Offs
Currently in Progress...


## Alternatives
Currently in Progress...



# &#128221; Application
Understanding some of the most well-known use cases of a concept is crucial for grasping its practical relevance and potential impact in real-world scenarios. Additionally, familiarizing oneself with practical problems and practicing their solutions ensures that you retain essential details and develop a deep, intuitive understanding of the concept's capabilities and limitations.


## Common Use Cases
- Simulation
- Sampling
- Numerical Analysis
- Computer Programming
- Decision Making
- Aesthetics
- Recreation
- Cryptography
- Gaming


## Some Practical Problems
Currently in Progress...



# &#x1F559; Origins
In the early days, people relied on manual methods to generate random numbers for both scientific and everyday purposes. These methods included tossing coins, rolling dice, or drawing cards. The journey toward mechanical random number generation began with **Leonard Henry Caleb Tippett's** **1927** invention of a table containing over 40,000 random digits. This marked a significant milestone, paving the way for subsequent innovations, such as the **1939** machine by the British statisticians **Maurice George Kendall** and **Bernard Babington Smith**, which produced a table of 100,000 random digits.

In the realm of computer science, a major breakthrough came in **1946** when Hungarian-American mathematician and physicist **John von Neumann** introduced the concept of generating random numbers through a computer’s arithmetic operations with his middle square method. Although deterministic, this method was effective for many applications where the appearance of randomness was sufficient. Subsequent advancements included the development of the Lehmer generator in **1949** by American mathematician **Derrick Henry Lehmer** and the creation of the Linear Congruential Generator by **W. E. Thomson** and **A. Rotenberg** in **1958**. Modern examples of RNGs include the Mersenne Twister by Japanese mathematicians and computer scientists **Makoto Matsumoto** and **Takuji Nishimura** in **1997** and xorshift in **2003** by American mathematician and computer scientist **George Marsaglia**, both of which have become widely used.

Today, companies like **Cloudflare** have taken innovative approaches to RNG, exemplified by their use of a wall of about 100 lava lamps in their headquarters. A camera captures images of these lamps at regular intervals, converting the dynamic and unpredictable movements into a series of random numbers. These numbers serve as the foundation for creating secure cryptographic keys and other essential random-based operations for their services. This approach exemplifies how RNG is becoming increasingly critical in security, simulations, and various cutting-edge technologies.



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../#-contacts).



# &#128591; Credits
&#128218; **Books:**
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven S. Skiena
  - Section 13.7: Random Number Generation
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 10.4.1: Random-Number Generators
- **"The Art of Computer Programming, Volume 2: Seminumerical Algorithms" (3rd Edition)** — by Donald Ervin Knuth
  - Section 3: Random Numbers

---  
&#127760; **Web-Resources:**  
- [Statistical Analysis](https://www.random.org/analysis/)
- [Random number generation](https://en.wikipedia.org/wiki/Random_number_generation) (Wikipedia)
- [List of random number generators](https://en.wikipedia.org/wiki/List_of_random_number_generators) (Wikipedia)
- [Understanding Entropy: The Key to Secure Cryptography and Randomness](https://blog.netdata.cloud/understanding-entropy-the-key-to-secure-cryptography-and-randomness/)
- [How do lava lamps help with Internet encryption?](https://www.cloudflare.com/ru-ru/learning/ssl/lava-lamp-encryption/)
- [<random\>](https://cplusplus.com/reference/random/)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)