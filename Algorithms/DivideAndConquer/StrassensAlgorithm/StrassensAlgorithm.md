# &#128209; Table of Contents
- [💡 Overview](#-overview)
- [💻 Implementation](#-implementation)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [⏳ Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
The **Stassen's Algorithm** is undoubtedly a well-known algorithm for matrix multiplication, heavily reliant on the idea of divide and conquer approach. This subsection aims to establish a solid foundation for complex algorithmic designs and strengthen comprehension of problem-solving strategies by exploring this illustrative example.
<p align="center"><img src="./img/Strassens.png"/></p>

---
The core idea behind Strassen's algorithm was to use a divide-and-conquer strategy, which involves recursively dividing the initial matrix into equal-sized submatrices, and employing additional computations and rearrangements of matrix elements to reduce the number of multiplications to 7, compared to the standard mathematical algorithm with 8, which is the dominant factor contributing to the overall time complexity. This reduction could lead to computational savings, as it transitions the whole operation's time complexity from $O(n^3)$ to $O(n^{2.81})$, which is particularly valuable for large matrices. However, the overhead that comes with the implementation negatively affects smaller matrices. Determining the optimal range for matrix size is relative and depends on hardware architecture, implementation details, and specific characteristics of the matrices being multiplied. As a general estimation, the optimal range typically falls between $32$ and $128$ for most modern computing environments. Also, it is crucial to mention not the best precision for floating numbers due to the nature of its computation.

> Note: To ensure the division proceeds correctly, this algorithm conceptually requires that all of the matrices have sizes that are powers of two. Even though it is possible to fill "missing" rows and columns with zeros to achieve required matrices, for educational purposes it would only obscure the concept with excessive operations (and practically I haven't seen people do that at all).

---
**Algorithm Steps (for matrices with sizes of powers of two):**
1. Divide two matrices $A$ and $B$ of size $n×n$ into four equal-sized submatrices.
2. Compute the intermediate submatrix products:
   - $P_{1} = (A_{11} + A_{22})(B_{11} + B_{22})$
   - $P_{2} = (A_{21} + A_{22}) B_{11}$
   - $P_{3} = A_{11}(B_{12} + B_{22})$
   - $P_{4} = A_{22}(B_{21} + B_{11})$
   - $P_{5} = (A_{11} + A_{12})B_{22}$
   - $P_{6} = (A_{21} + A_{11})(B_{11} + B_{12})$
   - $P_{7} = (A_{12} + A_{22})(B_{21} + B_{22})$
3. Compute the resulting submatrices of the product matrix $C$:
   - $C_{11} = P_{1} + P_{4} - P_{5} + P_{7}$
   - $C_{11} = P_{3} + P_{5}$
   - $C_{21} = P_{2} + P_{5}$
   - $C_{22} = P_{1} + P_{3} + P_{2} + P_{6}$
4. Combine the resulting submatrices to form the final product of matrix $C$.



# &#x1F4BB; Implementation
Currently in Progress...



# &#128202; Analysis
Currently in Progress...



# &#128221; Application
Currently in Progress...



# &#x23F3; Origins
Currently in Progress...



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../../#-contacts).



# &#128591; Credits
&#128218; **Books:**
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 4: Divide-and-Conquer
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 10.2: Divide and Conquer
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven Skiena
  - Section 4.10: Divide-and-Conquer

---  
&#127760; **Web-Resources:**  
- [Strassen algorithm](https://en.wikipedia.org/wiki/Strassen_algorithm) (Wikipedia)
- [Strassen's Algorithm](https://www.youtube.com/watch?v=D1GRgMfeRNk&ab_channel=%D0%9A%D0%B0%D1%84%D0%B5%D0%B4%D1%80%D0%B0%D0%91%D0%98%D0%A1) (Lecture)


# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)