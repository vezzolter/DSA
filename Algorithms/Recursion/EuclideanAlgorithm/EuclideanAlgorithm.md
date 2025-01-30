# &#128209; Table of Contents
- [💡 Overview](#-overview)
  - [Introduction](#introduction)
  - [Important Details](#important-details)
  - [Algorithm Steps (Recursive)](#algorithm-steps-recursive)
- [💻 Implementation](#-implementation)
  - [Design Decisions](#design-decisions)
  - [Complete Implementation](#complete-implementation)
  - [Detailed Walkthrough](#detailed-walkthrough)
  - [Call Stack Interaction](#call-stack-interaction)
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
The **Euclidean Algorithm** is one of the oldest and most efficient methods for computing the greatest common divisor (GCD) of two integers, widely used in number theory, cryptography and various other algorithmic applications. It is named after the ancient Greek mathematician Euclid, who first described it in his work Elements. Knowledge and understanding of it, lays a solid foundation for algorithmic design and tackling more complex problem-solving strategies.
<p align="center"><img src="./Images/EuclideanAlgorithm.png"/></p>


## Introduction
The core idea behind finding the GCD of two integers using the Euclidean algorithm is that we repeatedly replace the larger number with its remainder when divided by the smaller number, continuing until one of the numbers becomes zero. The last nonzero number is the GCD. Mathematically, this is expressed as:

$
\gcd(a, b) =
\begin{cases} 
b, & \text{if } (a \mod b) = 0 \\  
\gcd(b, a \mod b), & \text{otherwise}
\end{cases}
$


## Important Details
1. The algorithm operates on **two non-negative integers**.

2. The core property of algorithm lies in the fact that equation $\gcd(a, b) = \gcd(b, a \mod b)$ holds at every step, ensuring that the **GCD remains unchanged** throughout the process.

3. The algorithm can be implemented both **recursively and iteratively**, where the recursive approach mirrors the mathematical definition, while the iterative version is more efficient as it avoids function call overhead.

4. There are many other interesting concepts related to the Euclidean Algorithm, such as Bézout’s identity, the extended Euclidean algorithm, and its connection to LCM, but the most essential ones for a basic understanding of the algorithm have been covered.


## Algorithm Steps (Recursive)
1. Define the base case, based on the rule $\gcd(a, 0) = a$.
2. Define the recursive case, based on the rule $\gcd(a, b) = \gcd(b, a \mod b)$.



# &#x1F4BB; Implementation
The program prompts the user to input two non-negative integers, computes their GCD using a recursive implementation of the Euclidean Algorithm, and displays the result.  
<p align="center"><img src="./Images/Demonstration.png"/></p>


## Design Decisions
To prioritize simplicity and emphasize algorithm itself, several design decisions were made:
- Assuming valid input values from the user.
- Omitting certain optimizations to the algorithm.


## Complete Implementation
Algorithm implemented within the function `euclidean()`, which is declared in [EuclideanAlgorithm.h](https://github.com/vezzolter/DSA/blob/euclidean/Algorithms/Recursion/EuclideanAlgorithm/Include/EuclideanAlgorithm.h) header file and defined in [EuclideanAlgorithm.cpp](https://github.com/vezzolter/DSA/blob/euclidean/Algorithms/Recursion/EuclideanAlgorithm/Source/EuclideanAlgorithm.cpp) source file. This approach is adopted to ensure encapsulation, modularity and compilation efficiency. Examination of factorial computation is conducted within the `main()` function located in the [Maincpp](https://github.com/vezzolter/DSA/blob/euclidean/Algorithms/Recursion/EuclideanAlgorithm/Source/Main.cpp) file. Below you can find related code snippets.

```cpp
int euclidean(int a, int b) {
	if (b == 0) { return a; }
	return euclidean(b, a % b);
}
```


## Detailed Walkthrough
Currently in Progress...


## Call Stack Interaction
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
&#128218; **Books:**
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 31.2: Greatest common divisor
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 5.1: Recursive Algorithms
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 2.4: Running-Time Calculations
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven S. Skiena
  - Section 9.2.3: Least Common Multiple

---
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 5: Recursion

---
&#127760; **Web-Resources:**
- [Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm) (Wikipedia)
- [Greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) (Wikipedia)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)