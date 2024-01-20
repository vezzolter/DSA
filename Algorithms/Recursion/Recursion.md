# &#128209; Table of Contents
- [💡 What is Recursion](#-what-is-recursion)
  - [Implementation](#implementation)
  - [Call Stack](#call-stack)
  - [Pros and Cons](#pros-and-cons)
- [🎨 Types of Recursion](#-types-of-recursion)
  - [Single vs Multiple](#single-vs-multiple)
  - [Direct vs Indirect](#direct-vs-indirect)
  - [Tail Recursion](#tail-recursion)
- [📊 Analysis of Recursion](#-analysis-of-recursion)
- [📝 Usage of Recursion](#-usage-of-recursion)
- [⏳ Historical Notes](#-historical-notes)
- [🤝 Contributing](#-contributing)
- [📧 Contact Information](#-contact-information)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)


# &#128161; What is Recursion

**Recursion** is a widely used idea in computer science to solve complex problems by breaking them down into simpler ones. It helps to develop elegant & efficient data structures and algorithms for all manner of applications. Many important implementations use recursion, so it's important to understand the concept.

**Recursive Algorithm** — is one that solves a problem by solving smaller instances of the same problem. Implemented via recursive functions.


## Implementation

**Recursive Function** — is one that calls itself and has two main components:
1. **Base Case** — represents a situation, where the solution is directly known (already provided) without requiring further recursion.
2. **Recursive Case** — represents other situation, where the solution to the bigger problem is expressed in terms of smaller problems.
  
Not all mathematically recursive functions are efficiently (or correctly) implemented by C++’s simulation of recursion. Recursion is used when it makes the solution clearer. In order to make a good use of this approach, it's worth to consider a few deducable guidelines for designing:

1. **Termination conditions** — there must always be some base cases that can be solved without resorting to recursion. Otherwise it may lead to infinite recursion.
2. **Making progress** —  it's essential that each recursive call contributes to progress towards reaching a base case, making sure that termination conditions are reachable.
3. **Trust the encapsulation** — assume the functionality of all recursive calls is correct. This attempt to trace the sequence of calls, may spend unnecessary time, which actually, can be an indication of a good use of recursion, since the computer is being allowed to work out the complicated details.
4. **No duplicating** — the recursion should avoid duplicating work by solving the same instance of a problem in distinct recursive calls, because it could lead to inefficiencies and unnecessary computations.


## Call Stack
Currently in progress...


## Pros and Cons
Currently in progress...



# &#127912; Types of Recursion
Currently in progress...


## Single vs Multiple
Currently in progress...


## Direct vs Indirect
Currently in progress...


## Tail Recursion
Currently in progress...

# &#128202; Analysis of Recursion
Currently in progress...




# &#128221; Usage of Recursion
Currently in progress...


# &#x23F3; Historical Notes
Currently in progress...


# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../#-contributing).



# &#128231; Contact Information
For contact details and additional information, please refer to the [root directory's contact information section](../../#-contact-information).



# &#128591; Credits
&#128218; **Books:**
- **"Grokking Algorithms"** — by Aditya Bhargava
  - Section 3: Recursion.
- **"Data Structures and Algorithm Analysis in C++""** — by Mark A. Weiss
  - Section 1.3: A Brief Introduction to Recursion
- **"Algorithms in C++, Parts 1-4"** — by Robert Sedgewick
  - Section 5: Recursion and Trees.

&#127891;**Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/?LSNPUBID=JVFxdTr9V80&ranEAID%3B=JVFxdTr9V80&ranMID%3B=39197&ranSiteID%3B=JVFxdTr9V80-_3GVcwGZFWT4XsSuZYrgGA&utm_source=adwords&utm_medium=udemyads&utm_campaign=DSA_Catchall_la.EN_cc.ROW&utm_content=deal4584&utm_term=_._ag_88010211481_._ad_535397282064_._kw__._de_c_._dm__._pl__._ti_dsa-406594358574_._li_9061020_._pd__._&matchtype=&gad_source=1&gclid=CjwKCAiA3aeqBhBzEiwAxFiOBgRFL7RkV-WJI9tPKml75et478Ai5oJigSKAivJ2txZ9Jhi0mhsTdxoC_foQAvD_BwE) on Udemy
   - Section 5: Recursion

&#127760;**Web-Resources:**
- [Recursion (Computer Science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))
- [Introduction to Recursion](https://www.geeksforgeeks.org/introduction-to-recursion-data-structure-and-algorithm-tutorials/)
- [Fundamentals of Recursion in Programming](https://www.enjoyalgorithms.com/blog/recursion-explained-how-recursion-works-in-programming)
- [Recursive Functions](https://www.geeksforgeeks.org/recursive-functions/)
- [Types of Recursion](https://datatrained.com/post/types-of-recursion/)
- [What is Tail Recursion](https://www.geeksforgeeks.org/tail-recursion/)
- [Tail Call](https://en.wikipedia.org/wiki/Tail_call)
- [Tail Call Optimization](https://wiki.c2.com/?TailCallOptimization)
- [Recursion in Data Structure](https://www.codingninjas.com/studio/library/types-of-recursion)
- [Recursion in C++](https://favtutor.com/blogs/recursion-cpp)
- [Top 50 Problems on Recursion Algorithm asked in SDE Interviews](https://www.geeksforgeeks.org/top-50-interview-problems-on-recursion-algorithm/)
- [30 Recursion Interview Questions and Coding Exercises for Programming Interviews](https://medium.com/javarevisited/30-recursion-interview-questions-and-coding-exercises-for-programming-interviews-2816302e9ab)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)