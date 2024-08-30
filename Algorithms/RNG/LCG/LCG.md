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
  - [Algorithm Characteristics](#algorithm-characteristics)
  - [Algorithm Comparison](#algorithm-comparison)
- [📝 Application](#-application)
  - [Common Use Cases](#common-use-cases)
  - [Some Practical Problems](#some-practical-problems)
- [🕙 Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
The **Linear Congruential Generator (LCG)** is a simple, pretty deterministic and widely used algorithm for generating pseudo-random numbers. The name of it  derives from its core operation, which involves a linear congruence equation to produce the next number in the sequence. Knowledge and understanding of it lay a solid foundation for algorithmic design and tackling more complex problem-solving strategies.
<p align="center"><img src="./Images/LCG.png"/></p>


## Introduction
LCG operates iteratively, at each step it takes the current number (initially its a seed) and generates the next number using a linear congruence equation of the form:  
$$X_{n+1} = (a \times X_n + c) \mod m$$

Where:
- $n$ — current number (initially its a seed).
- $m$ — modulus, determines the range of possible values that LCG can generate ($0$ to $m-1$).
- $a$ — multiplier, ensures good distribution of values across the range.
- $c$ — increment, ensures that the sequence doesn't repeat too soon.


## Important Details
Algorithm is highly depended on choosing correct parameters in order to elicit a great sequence in terms of randomness:
   - $m$ typically should be a power of $2$, because it allows for efficient computation using bitwise operations and covers the entire possible value set for typical data type like 32-bit or 64-bit integers.  
   E.g. $m = 2^{32} = 4294967296$; $m = 2^{64} = 18446744073709551616$.

   - $a-1$ should be divisible by all prime factors of $m$, because this is one of the great ways for the LCG to traverse through the entire range of possible values without skipping any.   
   E.g. $a = 1664525$; $a = 6364136223846793005$.

   - $c$ should be relatively prime to $m$, because if $c$ and $m$ share a common factor greater than $1$, the sequence could become trapped in a small subset of possible values, repeating more frequently and failing to achieve a full period.   
   E.g. $c = 1013904223$, $c = 1442695040888963407$.


## Algorithm Steps
1. Define parameters according to the chosen criteria.
2. Use the formula to generate the pseudo-random number.
3. Update the seed for the next iteration ($X_n\text{ to }X_{n+1}$).
4. Repeat this process to generate required amount of numbers.



# &#x1F4BB; Implementation
Currently in Progress...


## Design Decisions
Currently in Progress...


## Complete Implementation
Currently in Progress...


## Detailed Walkthrough
Currently in Progress...



# &#128202; Analysis
Currently in Progress...


## Algorithm Characteristics
Currently in Progress...


## Algorithm Comparison
Currently in Progress...



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
- [Linear congruential generator](https://en.wikipedia.org/wiki/Linear_congruential_generator)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)