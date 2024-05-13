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
**Sorting** is a widely used operation in computer science to arrange items in a particular order. It helps to organize data efficiently in various algorithms and for all manner of applications, therefore it is important to truly understand the concept.
<p align="center"><img src="./img/Sorting.png"/></p>

---
**Essential Terminology:**
- **Sorting Algorithm** — is set of steps used to obtain a particular order of elements within a collection of data.
  - **Specific Order** — is an arrangement of elements within a collection based on a defined set of criteria. 
  - **Criterion** — is a rule used to make the decisions about the order of elements.
- **Collection** — is a data structure, which is used to group multiple elements together.
  - **Table** — is a small collection of all elements.
  - **File** — is a big collection of all elements.
  - **Database** — is a large collection of all elements.
- **Element/Record/Item** — is an individual entity within a collection.
  - **Index/Key of Element** — is a position of an element within collection.
  - **Value/Data of Element** — is an actual information stored within the element.



# &#x1F4BB; Implementation
The list of known sorting algorithms is extensive and continues to grow. When it comes to implementation, some share some common ideas, while others possess distinctive characteristics. The choice between them depends on the specific requirements of the cases at hand. There are plenty of metrics to classify algorithms by (each of which can impose certain specifications on implementation), most used of them are:

- **Comparison Approach:**
   - **Comparison-Based** — algorithm sorts elements by comparing them using pairwise comparisons to determine their relative order.
   - **Non-Comparison-Based** — algorithm sorts elements without explicitly comparing them, often using specific properties of data.

- **Time Complexity:**
   - $O(nlogn)$ — effecient performance, divide the input into smaller subproblems and solve them recursively.
   - $O(n)$ — proportional to the size of the input data, each element is compared or moved at most once.
   - $O(n^2)$ — less eficient, typically involve nested loops or multiple comparisons.
   - **Other** — although they are in the minority, it is worth mentioning them.
  
- **Space Complexity:**
   - **In-Place** $\big(O(1)\big)$  — algorithm doesn't require any additional memory.
   - **Out-of-Space** $\big(O(n)/O(nlogn)/...\big)$ — algorithm does require some additional memory.

- **Stability:**
   - **Stable** — algorithm preserves the relative order of equal elements, i.e. if two elements from the input are considered equal, stable algorithm ensures that they will maintain this order in sorted output.
   - **Unstable** — algorithm doesn't guarantee the preservation of the relative order of equal elements; i.e. they can either be swapped or kept, algorithm doesn't consider the original positions.

- **Adaptability:**
   - **Adaptive** — algorithm adjusts its overall behavior (sequence of operations) based on the initial order of elements to improve performance.
   - **Non-Adaptive** — algorithm processes data through the same path of steps, regardless of their values.

- **Directness:**
   - **Direct** — algorithm sorts elements directly manipulating themselves.
   - **Indirect** — algorithm utilizes some sort of a pointer onto elements in order to sort them, typically it is done because moving huge chunks can be more resourceful operation compared to little shortcuts.

- **Storage:**
   - **Internal** — algorithm takes place entirely within the main memory (RAM) of computer.
   - **External** — algorithm takes place within other devices (e.g. hard disk), typically due to their huge size.



# &#128202; Analysis
The analysis of sorting algorithms in general relies on the assessment of previously mentioned metrics individually for each case. For a more in-depth examination of any specific algorithm, simply navigate to its corresponding folder via list below:
- [Sorting.md](https://github.com/vezzolter/DSA/tree/main/Algorithms/Sorting/Sorting.md) ✅
- [Bubble Sort](https://github.com/vezzolter/DSA/tree/main/Algorithms/Sorting/BubbleSort) ✅
- [Selection Sort](https://github.com/vezzolter/DSA/tree/main/Algorithms/Sorting/SelectionSort) ✅
- [Insertion Sort](https://github.com/vezzolter/DSA/tree/main/Algorithms/Sorting/InsertionSort) ✅
- [Merge Sort](https://github.com/vezzolter/DSA/tree/main/Algorithms/Sorting/MergeSort) ✅
- [Quicksort](https://github.com/vezzolter/DSA/tree/main/Algorithms/Sorting/Quicksort) ✅
- Heap Sort
- Radix Sort
- Counting Sort
- Bucket Sort
 - Shell Sort



# &#128221; Application
**Some of the Most Well-Known Use Cases in Various Fields:**
- **Search and Retrieval** — sorting facilitates efficient searching and retrieval operations in various data structures like arrays, trees, and hash tables. Sorted data allows for faster lookup times using techniques like binary search.
- **Ordering and Ranking** — sorting used for arranging data in ascending or descending order based on specific criteria, such as numerical values, alphabetical order, or timestamps. This enables easier analysis, visualization, and decision-making processes.
- **Data Presentation and Visualization** — comes from previous, sorted data is often presented visually in charts, graphs, and reports to convey trends, patterns, and insights effectively. Visualization tools rely on sorted data to generate meaningful and informative visual representations.
- **Optimization Problems** — sorting is used in various optimization problems, such as job scheduling, task prioritization, and resource allocation. Sorted data enables the efficient allocation of resources and scheduling of tasks based on predefined criteria or constraints.
- **Data Deduplication** — sorting helps identify and remove duplicate entries or records from datasets efficiently. By sorting the data, duplicate entries can be easily identified and eliminated, improving data quality and reducing storage overhead.

---
**Common Practical Problems:**
- Sort elements by frequency.
- Sort an array in wave form.
- Widest vertical area between two points containing no points.
- Find missing elements of a range.
- Majority element.
- Sort an array/list of 0s, 1s and 2s.
- Remove all duplicates.
- Find the point where maximum intervals overlap.
- Sort a matrix in all way increasing order.
- Find surpasser count of each element in array.
- Count distinct occurrences as a subsequence.
- Minimum absolute difference.
- Count minimum number of subsets (or subsequences) with consecutive numbers.



# &#x1F559; Origins
While sorting as concept emerged unknown-long time ago and throughout the whole world naturally, the development of sorting algorithms dates back in the early days of computing. One notable early milestone in the computer science's history of sorting methods goes back in the late **1880s**, when American genius **Herman Hollerith** started to work on tabulating machines and came up with efficient solution to automate the manual process by formulating an algorithm, which only later led to the **Radix Sort**.

The breakthrough came with the invention of divide-and-conquer sorting algorithm **Merge Sort** by Hungarian-American computer scientist **John von Neumann** in **1945** and other pioneers, that were born in the **1950s** such as **Bubble Sort** and the **Selection Sort**, which were simple but quite inefficient and thus impractical for large datasets. Later the famous **Quicksort** was developed by British computer scientist **Tony Hoare** in **1959** and published in **1961**, which still remains a commonly used algorithm for sorting. Summarizing, these individuals, among others, played crucial roles in integrating sorting into practical programming paradigms.



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../#-contacts).



# &#128591; Credits
&#128218; **Books:**
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 8: Sorting in Linear Time
  - Section 9: Medians and Order Statistics
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 6: Elementary Sorting Methods
  - Section 7: Quicksort
  - Section 8: Merging and Mergesort
  - Section 9: Priority Queues and Heapsort
  - Section 10: Radix Sort
  - Section 11: Special-Purpose Sorts
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 7: Sorting
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven S. Skiena
  - Section 4: Sorting and Searching
  - Section 14: Combinatorial Problems
- **"The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd Edition)** — by Donald Ervin Knuth
  - Section 5: Sorting

---
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 20: Sorting Techniques

---  
&#127760; **Web-Resources:**  
- [Sorting Algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm) (Wikipedia)
- [Sorting Algorithms in Computer Science](https://www.studysmarter.co.uk/explanations/computer-science/algorithms-in-computer-science/sorting-algorithms/)
- [Sorting Algorithms Explained](https://www.freecodecamp.org/news/sorting-algorithms-explained/)
- [Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Comparative Analysis of Comparison and Non Comparison based Sorting Algorithms](https://www.ijcaonline.org/archives/volume175/number28/fenyi-2020-ijca-920813.pdf)
- [The first sorting algorithm and the founding of IBM](https://www.linkedin.com/pulse/first-sorting-algorithm-founding-ibm-nilesh-d/)
- [The Evolution of Sorting Algorithms Over the Years](https://dev.to/shhossain/the-evolution-of-sorting-algorithms-over-the-years-bubble-sort-to-ai-driven-sort-31pg#:~:text=The%20birth%20of%20sorting%20algorithms,them%20impractical%20for%20large%20datasets.)




# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)