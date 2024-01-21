# &#128209; Table of Contents
- [💡 What is Recursion](#-what-is-recursion)
- [💻 Implementation](#-implementation)
- [🎨 Types of Recursion](#-types-of-recursion)
- [📚 Call Stack](#-call-stack)
- [📝 Application of Recursion](#-application-of-recursion)
- [📊 Analysis of Recursion](#-analysis-of-recursion)
- [⏳ Historical Notes](#-historical-notes)
- [🤝 Contributing](#-contributing)
- [📧 Contact Information](#-contact-information)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)


# &#128161; What is Recursion

**Recursion** is a widely used idea in computer science to solve complex problems by breaking them down into simpler ones. It helps to develop elegant & efficient data structures and algorithms for all manner of applications. Many important implementations use recursion, so it's important to understand the concept.

As a practical instance showcasing the nonmathematical application of recursion, let's turn to the example outlined by Mark Allen Weiss in his work "Data Structures and Algorithm Analysis in C++", listed below:

> Consider a large dictionary. Words in dictionaries are defined in terms of other words. When we look up a word, we might not always understand the definition, so we might have to look up words in the definition. Likewise, we might not understand some of those, so we might have to continue this search for a while. Because the dictionary is finite, eventually either (1) we will come to a point where we understand all of the words in some definition (and thus understand that definition and retrace our path through the other definitions) or (2) we will find that the definitions are circular and we are stuck, or that some word we need to understand for a definition is not in the dictionary.



# &#x1F4BB; Implementation

**Recursive Algorithm** — is one that solves a problem by solving smaller instances of the same problem. Implemented via recursive functions.

**Recursive Function** — is one that calls itself and has two main components:
1. **Base Case** — represents a situation, where the solution is directly known (already provided) without requiring further recursion.
2. **Recursive Case** — represents other situation, where the solution to the bigger problem is expressed in terms of smaller problems.

Not all mathematically recursive functions are efficiently (or correctly) implemented by C++’s simulation of recursion. Recursion is used when it makes the solution clearer. In order to make a good use of this approach, it's worth to consider a few deducable guidelines for designing:

1. **Termination conditions** — there must always be some base cases that can be solved without resorting to recursion. Otherwise it may lead to infinite recursion, which cause stack overflow problem (refer to '[Call Stack](#call-stack)' subsection).
2. **Making progress** —  it's essential that each recursive call contributes to progress towards reaching a base case, making sure that termination conditions are reachable.
3. **Trust the encapsulation** — assume the functionality of all recursive calls is correct. This attempt to trace the sequence of calls, may spend unnecessary time, which actually, can be an indication of a good use of recursion, since the computer is being allowed to work out the complicated details.
4. **No duplicating** — the recursion should avoid duplicating work by solving the same instance of a problem in distinct recursive calls, because it could lead to inefficiencies and unnecessary computations.



# &#127912; Types of Recursion
Currently in progress...



# &#128218; Call Stack

Another vital consideration when discussing recursion is the role of the Call Stack in it.

**Call Stack** — is a region of memory, that stores information about the active function calls in a program by forming a stack (pile) of frames for each caller, i.e. tracks the order of calls. It operates based on the principles of a fundamental abstract data structure known as a Stack _(a link to the repository's dedicated section will be added in the near future)_, meaning items that entered the last are the first to be removed or simply Last In First Out (LIFO).

**Stack Frame** — section of memory, allocated on stack, which stores function related information, such as: return adress, parameters, local variables, saved registers, flags, frame pointer. As the function executes, its frame provides the necessary context. When the function completes, its stack frame is popped off the stack, and control returns to the calling function.

The detailed interaction of recursion with the Call Stack is actually quite complex topic with lots of intricacies, particularly in the context of C++. This complexity arises from various factors, including: templates, diverse variables/parameters types (static, global, ...), inlining mechanisms, aspects of OOP, exception handling, and more. Attempting to govern all of those moments in a single list can be quite challenging. With that in mind, I aim to offer a general overview of how functions interact with the Call Stack below.

**Fundametal Aspects of Call Stack Interaction:**
1. When a function is called, the function's stack frame is added to the top of the call stack.
2. When function (a) calls another function (b), the variables' state of the calling function (a) is still stored in memory.
3. Each call to a function has its own set of local variables; therefore, it's not possible to access a different function's set of a local variables.
4. When the termination condition is reached, the function returns its value to the calling function, and memory is de-allocated, allowing the process to continue

Using stack is convenient, because there is no need to manually keep tracking the pile, but saving all that info can take up a lot of memory. In some programming languages, the maximum size of the call stack is much less than the space available in the heap, and recursive algorithms tend to require more stack space than iterative algorithms. Consequently, these languages sometimes place a limit on the depth of recursion to avoid stack overflows.

**Stack Overflow** — is a runtime error, that occurs when a program's call stack exceeds its allocated size, potentially causing program termination, data loss, resource cleanup issues, systen instability and other destructive behaviour if it is not handled appropriately.

Common causes for exceeding stack limits include uncontrolled recursion, infinite loops, deep base cases, excessive consumption in multithreaded environments, and overuse of exception handling. The key is to identify recursive behavior and handle it appropriately. In large projects, simple but subtle details like the example below can be easily overlooked:
```cpp
// Since 'i' is an unsigned character, it will be converted to an 8-bit value,
// which, upon reaching 255, will overflow and return to 0, thus infinite loop
unsigned char halfLimit = 150;

for (unsigned char i = 0; i < 2 * halfLimit; ++i)
{
  // do something
}
```



# &#128221; Application of Recursion

In computer science, **iteration** and **recursion** stand out as two fundamental **problem-solving strategies**. Both are equally expressive: they involve executing instructions repeatedly until task is finished. Moreover recursion can be replaced by iteration with an explicit call stack, while iteration can be replaced with tail recursion. The preference for one approach depends on the specific problem under consideration and the programming language being used.

**Iteration** finds its strength in performance-oriented scenarios, and in many cases, there is no inherent advantage to using recursion. However, if converting recursion into a straightforward loop structure poses difficulties, it might be an indication that recursion becomes a prominent choice.

**Recursion**, as it was said, is more suitable approach in cases where implementing an algorithm using iteration is challenging, thefore recursion provides clear and natural solutions. However, if feasible, converting recursion into iteration is often preferred for improved performance and resource utilization.

To successfully convert recursion into a loop, it's essential for the recursion to be **tail-recursive**. Tail recursion is characterized by having the recursive call as the last statement executed by the function. In other words, the function's calls involve a single invocation of the recursive call followed by an immediate return of the result without additional processing or calculation. When utilizing a compiler or interpreter that treats tail-recursive calls as jumps rather than function calls, the program becomes essentially iterative. Therefore, equivalent to using control structures like the "for" and "while" loops, which saves both space and time.

---

**Some of the Most Well-Known Use Cases:**
- **Sortings** — recursive algorithms leverage recursion to partition the data into smaller subarrays or sublists, subsequently sorting and merging them to achieve the final ordered result.
- **Divide-and-Conquer** — numerous algorithms employing a divide-and-conquer strategy, like the binary search, utilize recursion to decompose the problem into more manageable subproblems.
- **Memoization (Dynamic Programming)** — as long as this technique entails storing the outcomes of resource-intensive function calls and retrieving the cached result when encountering identical inputs in subsequent calls, recursive functions are often employed for those problems.
- **Backtracking** — backtracking algorithms are used to solve problems that involve making a sequence of decisions, where each decision depends on the previous ones. These algorithms can be implemented using recursion to explore all possible paths and backtrack when a solution is not found.
- **Trees and Graphs** — recursion finds common application in traversing and searching data structures like trees and graphs. Recursive algorithms prove effective in systematically exploring all nodes or vertices within a tree or graph.
- **Permutations and Combinations** — recursive algorithms are often used to generate permutations and combinations of a set of elements.

---

**Related Problems:**
- Factorial Calculation
- Fibonacci Sequence
- Tower of Hanoi Puzzle
- Depth-First Search (DFS)
- Breadth-First Search (BFS)
- Binary Search
- Merge Sort
- Quick Sort
- Maze Solving
- N-Queens Problem
- Palindrome Check
- Subset Generation
- Permutations
- Combinations
- Ackermann Function
- Pascal's Triangle
- Parentheses Matching
- Expression Evaluation
- Inversion Count



# &#128202; Analysis of Recursion
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
- [How stack frames work](https://nordvpn.com/ru/cybersecurity/glossary/stack-frame/#:~:text=A%20stack%20frame%2C%20often%20just,%2DOut%20(LIFO)%20manner.)
- [What are the benefits and drawbacks of using stack frames for nested function calls?](https://www.linkedin.com/advice/0/what-benefits-drawbacks-using-stack-frames-nested#:~:text=A%20stack%20frame%20is%20a,registers%20of%20the%20caller%20function.)
- [Difference Between Recursion and Iteration](https://www.enjoyalgorithms.com/blog/difference-between-iteration-and-recursion)
- [Types of Recursion](https://datatrained.com/post/types-of-recursion/)
- [What is Tail Recursion](https://www.geeksforgeeks.org/tail-recursion/)
- [Tail Call](https://en.wikipedia.org/wiki/Tail_call)
- [Tail Call Optimization](https://wiki.c2.com/?TailCallOptimization)
- [Recursion in Data Structure](https://www.codingninjas.com/studio/library/types-of-recursion)
- [Recursion in C++](https://favtutor.com/blogs/recursion-cpp)
- [Time Complexity Analysis of Recursive Function in DSA](https://www.enjoyalgorithms.com/blog/time-complexity-analysis-of-recursion-in-programming)
- [Top 50 Problems on Recursion Algorithm asked in SDE Interviews](https://www.geeksforgeeks.org/top-50-interview-problems-on-recursion-algorithm/)
- [30 Recursion Interview Questions and Coding Exercises for Programming Interviews](https://medium.com/javarevisited/30-recursion-interview-questions-and-coding-exercises-for-programming-interviews-2816302e9ab)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)