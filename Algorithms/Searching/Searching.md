# &#128209; Table of Contents
- [💡 What is the Searching](#-what-is-the-searching)
- [💻 Implementation](#-implementation)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [⏳ Historical Notes](#-historical-notes)
- [🤝 Contributing](#-contributing)
- [📧 Contact Information](#-contact-information)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; What is the Searching
**Searching** is a widely used operation in computer science to retrieve information. It helps to locate specific items or data within datasets in various algorithms and for all manner of applications, therefore it is important to truly understand the concept.
<p align="center"><img src="./img/searching.png"/></p>

---
**Essential Terminology:**
- **Searching Algorithm** — is a set of steps used to retrieve a particular element within a collection of data.
  - **Successful Search** — is an outcome in which algorithm found the element(-s) containing argument. 
  - **Unsuccessful Search** — is an outcome in which algorithm didn't the element(-s) containing argument.
- **Collection** — is a data structure, which is used to group multiple elements together.
  - **Table** — is a small collection of all elements.
  - **File** — is a big collection of all elements.
  - **Database** — is a large collection of all elements.
- **Element/Record/Item** — is an individual entity within a collection.
  - **Index/Key of Element** — is a position of an element within collection.
  - **Value/Data of Element** — is an actual information stored within the element.
- **Argument** — is a parameter passed to an algorithm, which provides the criteria, which will be used to find the desired element.
- **Criterion** — is a rule used to determine whether an element meets the requirements of the search.



# &#x1F4BB; Implementation
The list of known searching algorithms is extensive and continues to grow. When it comes to implementation, some share some common ideas, while others possess distinctive characteristics. The choice between them depends on the specific requirements of the cases at hand. There are plenty of metrics to classify algorithms by (each of which can impose certain specifications on implementation), most used of them are:

- **Search Strategies:**
   - **Linear Algorithms** — sequentially examine each element in the collection until the target is found or the end of the dataset is reached.
   - **Binary Algorithms** — operate on sorted datasets and repeatedly divide the search space in half until the target element is found
   - **Tree-Based Algorithms** — utilize tree data structures, such as binary search trees (BSTs), balanced binary search trees (AVL trees, Red-Black trees), or B-trees.
   - **Hashing Algorithms** — use hash functions to map keys to indices in an array (hash table).
   - **Graph-Based Algorithms** — explore graphs to find paths or relationships between nodes
   - **String Algorithms** — focus on finding occurrences of patterns within text or string data.
   - **Heuristic Algorithms** — use domain-specific knowledge or heuristic information to guide the search process towards more promising areas of the search space.
   - **Other** — although they are in the minority, it is worth mentioning them.
  
- **Time Complexities:**
  - $O(1)$ — occurs when the search operation takes the same amount of time regardless of the size of the dataset, usually via known key and straightforward access.
   - $O(log(n))$ — occurs when the search operation divides the search space in half with each step.
  - $O(n × log(n))$ — occurs when the time of search increases linearly with the size of collection and also influenced by logarithmic factor due to divide-and-conquer strategies.
   - $O(n)$ — occurs when the search operation examines each element one by one, therefore making its time proportional to the size of the collection.
   - $O(n^2)$ — can occur in certain nested loop-based search algorithms where each element is compared with every other element in the collection.
   - $O(2^n)$ — typically associated with brute-force search algorithms that explore all possible combinations of elements.
   - **Other** — although they are in the minority, it is worth mentioning them.
  
- **Auxiliary Space Complexity:**
   - **In-Place** $\big(O(1)\big)$  — algorithm does not require additional memory.
   - **Out-of-Space** $\big(O(n)/O(n×logn)/...\big)$ — algorithm does require some additional memory.  
   P.s. those terms used mostly only for sorting, even though they mean the same for both algorithms' classes.

- **Element's Mutability:**
   - **Static** — contents of the collection either rarely change or don't change at all.
   - **Dynamic** — contents of the collection frequently change.

- **Key Representation:**
   - **Actual Keys** — refers to the original keys or values used for identification and retrieval within the search algorithm.
   - **Transofrmed Keys** — refers to the keys, that have undergone some form of transformation (e.g. encryption, different format, preprocessing, etc) to optimize the search process.

- **Adaptability:**
   - **Adaptive** — algorithm adjusts its overall behavior (sequence of operations) based on the initial order of elements to improve performance.
   - **Non-Adaptive** — data processed through the same path of steps, regardless of their values.

- **Storage:**
   - **Internal** — algorithm takes place entirely within the main memory (RAM) of computer.
   - **External** — algorithm takes place within other storage devices (e.g. hard disk).



# &#128202; Analysis
Currently in Progress...



# &#128221; Application
**Some of the Most Well-Known Use Cases in Various Fields:**
- **Information Retrieval in Search Engines** —  search algorithms used to retrieve relevant information from vast amounts of data on the web by analyzing the content of web pages, index them based on keywords and relevance, and rank the results.
- **Pathfinding and Navigation** — type of search algorithms that efficiently find the shortest or most optimal path between two points in a graph or network, considering factors like distance, time, or cost.
- **Genetic Algorithms in Optimization** — type of search algorithms that mimic the process of natural selection and evolution to iteratively generate and improve solutions to complex optimization problems.
- **Game Development & Artificial Intelligence** — search algorithms are used to figure out a strategy, by searching through the possilities and picking the best move, also gamedev utilize pathfinding algorithms in building a route for a player.



---
**Common Practical Problems:**
- Find the largest three elements in an array.
- Find the closest pair.
- Find the missing and repeating number.
- Find a pair with the given difference.
- k largest(or smallest) elements in an array.
- Find all duplicates.
- Find a peak element.
- Search in an almost sorted array.
- Find the majority element.



# &#x23F3; Historical Notes
Currently in Progress...



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../#-contributing).



# &#128231; Contact Information
For contact details and additional information, please refer to the [root directory's contact information section](../../#-contact-information).



# &#128591; Credits
&#128218; **Books:**
- **"Grokking Algorithms: An Illustrated Guide for Programmers and Other Curious People"** — by Aditya Bhargava
  - Chapter 1.2: Binary Search
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Chapter 12: Symbol Tables and BSTs
  - Chapter 15: Radix Search
  - Chapter 16: External Searching
- **"The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd Edition)** — by Donald Ervin Knuth
  - Chapter 6: Searching

---
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 7: The Array ADT (Linear + Binary Search)

---  
&#127760; **Web-Resources:**  
- [Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm) (Wikipedia)
- [Searching algorithms compared](https://adacomputerscience.org/concepts/search_searching_compared)
- [Search algorithms and their implementations](https://codecoda.com/en/blog/entry/search-algorithms-and-their-implementations)
- [Searching Algorithms](https://www.geeksforgeeks.org/searching-algorithms/)


# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)