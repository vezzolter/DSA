# &#128209; Table of Contents
- [💡 Overview](#-overview)
- [💻 Implementation](#-implementation)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [🕙 Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
**Divide-and-Conquer** is a widely used problem-solving approach in computer science to solve complex problems by breaking them down into simpler ones. It helps to design elegant and efficient algorithms for all manner of applications, making it important to truly understand the concept.
<p align="center"><img src="./Images/DivideAndConquer.png"/></p>

---
**Essential Terminology:**
- **Problem** — is a task or challenge that requires a solution, typically defined by a set of inputs, constraints, and desired outputs. It can vary in complexity and scope, ranging from simple arithmetic calculations to complex optimization tasks.
  - **Sub Problem** — is a smaller, more manageable instance of the original problem.
- **Problem-Solving Strategy** — is a method of approaching a problem to find a solution.
- **Divide-and-Conquer** — is a strategy that consists of 3 steps: 
  1. **Divide** — brake down original problem into smaller, more manageable sub-problems.
  2. **Conquer** — solve each sub-problem independently.
  3. **Combine** — combine those solutions to form solution to the original problem.
- **Decrease and Conquer** — is a variation, which leaves only required subproblem and discards other, that are not considered further in the solution process because they don't contain the solution to the original problem, therefore this approach just simply reduces the size of the original problem; e.g. binary search divides problem in halves, but search occurs only in one.



# &#x1F4BB; Implementation
When it comes to implementation, the number of times people have resorted to using divide-and-conquer can't be counted. In fact, the majority of those scenarios share some common ideas, which are built through practice. Generally, there are two ways to achieve this behavior:
- **Recursion** — solves each sub-problem either by recursively dividing again or if small enough solves directly; e.g. merge sort.
- **Iteration** — divides the problem in each iteration of the loop until original problem is solved; e.g. binary search.

> Personal note: Since you can observe the ideas of divide-and-conquer in many other approaches (probably due to its extremely general steps), it could be quite confusing to determine which specific implementation is being considered. In most cases I have encountered, divide-and-conquer is associated with recursion. Therefore, I recommend associating it as the default approach, but not limiting your design thinking only to it.

---
Therefore, I will present some of the most illustrative examples specifically to enlighten the details of the divide-and conquer-approach:  
- [Strassen's Algorithm](https://github.com/vezzolter/DSA/tree/main/Algorithms/DivideAndConquer/StrassensAlgorithm)
- [Binary Search](https://github.com/vezzolter/DSA/tree/main/Algorithms/Searching/BinarySearch)
- [Merge Sort](https://github.com/vezzolter/DSA/tree/main/Algorithms/Sorting/MergeSort)
- Karatsuba Algorithm (Will be updated in the future...)



# &#128202; Analysis
**How to Analyze:**   
When an divide-and-conquer algorithm containts a recursive call to itself, it is possible to describe running time as [reccurence relation](https://github.com/vezzolter/DSA/tree/main/Algorithms/Analysis/Analysis.md), which can be solved in order to provide different bounds on performance. However, for algorithms like binary search, which are typically implemented iteratively, the same steps cannot be applied to estimate their complexity.

---
**Advantages:**
- **Improved Asymptotic Performance** — divide-and-conquer allows to reduce time complexity compared to naive approaches, which in a long run can greatly benefit efficiency of the algorithm.
- **Parallelism** — divide-and-conquer enables solving subproblems independently, making it an ideal approach to leverage multi-core processors.

---
**Disadvantages:**
- **Recursion Overhead** — divide-and-conquer's recursive calls impose additional complexity, which can outweight the benefits.
- **Memory Consumption** — divide-and-conquer requires extra space to perform some of its steps, which can be prohibitive in some environments with limited memory.
- **Non-Trivial Implementation** — divide-and-conquer is not a straightforward approach, division and merging processes may introduce additional complexities that make the algorithm harder to implement correctly.



# &#128221; Application
**Some of the Most Well-Known Use Cases:**
- **Sorting** — divide-and-conquer strategies are used in sorting algorithms to optimize the process of arranging data in a specific order. They achieve this by efficiently partitioning the data into smaller subsets, sorting each subset independently, and merging them back together to achieve the final sorted result; e.g. Merge sort, Quicksort, Heap sort.
- **Searching** — divide-and-conquer approach enhances searching algorithms by efficiently locating specific elements within a dataset. These algorithms partition the search space into smaller segments, recursively searching each segment, and converging on the target element or determining its absence, thereby facilitating efficient search operations; e.g. Binary search, maximum and minimum element search.
- **Matricex Operations** — divide-and-conquer techniques are applied to matrix operations. These techniques break down the matrices into smaller sub-matrices, perform computations recursively, and combine the results, enabling efficient matrix manipulations; e.g. Strassen's algorithm, recursive algorithms for matrix exponentiation
- **Computational Geometry** — divide-and-conquer algorithms are used in computational geometry to solve geometry problems. These algorithms partition the geometric space, solve sub-problems independently, and combine the results to achieve geometric solutions efficiently; e.g. Graham Scan, QuickHull, Voronoi diagrams.
- **Numerical Methods** — divide-and-conquer methods are used in numerical methods to solve mathematical problems using numerical approximations and algorithms. These methods break down the problem into smaller sub-problems, perform recursive computations, and combine the results to achieve efficient solutions; e.g. Simpson's Rule, Newton-Raphson method, Bisection method.

---
**Popular Related Problems:**
- Merge Sort
- Quick Sort
- Binary Search
- Closest Pair of Points
- Strassen's Algorithm for Matrix Multiplication
- Finding Maximum Subarray
- Computing Convex Hull
- Karatsuba Algorithm for Multiplication
- Closest Pair Problem
- Fast Fourier Transform (FFT)
- Finding the k-th Smallest/Largest Element in an Array
- Finding the Median of Two Sorted Arrays
- Counting Inversions in an Array
- Finding Majority Element
- Finding Peak Element in an Array



# &#x1F559; Origins
The idea of dividing one complex problem, solving them independently, and yielding the result dates back to ancient times, where it has been utilized for centuries in various cultures. In the realm of mathematics and computer science, the formalization and systematic study of divide-and-conquer algorithms began in the mid-20th century with the development of computer science as a field of study. Among the first introduced algorithms that utilized this idea were **Merge Sort** and **Quicksort**. From that point on, it gained widespread adoption and became a fundamental strategy in algorithm design and analysis.



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../#-contacts).



# &#128591; Credits
&#128218; **Books:**
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 4: Divide-and-Conquer
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 5.2: Divide and Conquer
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 10.2: Divide and Conquer
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven Skiena
  - Section 4.10: Divide-and-Conquer

---  
&#127760; **Web-Resources:**  
- [Divide-and-conquer algorithm](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm) (Wikipedia)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)