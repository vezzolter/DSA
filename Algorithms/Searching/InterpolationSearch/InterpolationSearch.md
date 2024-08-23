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
**Interpolation Search** is a search algorithm known for efficiently finding elements in a uniformly distributed ordered collection by estimating the position of the target value. The algorithm's name comes from the interpolation formula it uses to predict where the desired element is likely to be within the current search interval. Knowledge and understanding of it lay a solid foundation for algorithmic design and tackling more complex problem-solving strategies.
<p align="center"><img src="./Images/InterpolationSearch.png"/></p>


## Introduction
**Interpolation Search** optimizes the search process in an ordered collection by estimating the likely position of the target element using the values at the boundaries and applying linear interpolation.


## Important Details
- The algorithm is only applicable to sorted collections; otherwise, it may search the wrong parts of the data and return no result, even if the element is present.
- The algorithm requires specific data characteristics — data should be uniformly distributed, as the interpolation formula assumes a linear relationship between values. If the data is clustered, has irregular gaps, or includes many duplicates, the performance may degrade, making other approaches more reliable.


## Algorithm Steps
1. Make sure the collection is in sorted order.
2. Initialize the search interval with the lowest (`low`) and highest (`high`) indices of the collection.
3. While the `low` index is less than or equal to the `high` index and the target is within search interval:
   - Calculate the estimated position using the interpolation formula:  
     $\text{pos} = \text{low} + \frac{\text{target} - \text{arr[low]}}{\text{arr[high]} - \text{arr[low]}} \times (\text{high} - \text{low})$
   - Compare the target element with the element at the estimated position (`arr[pos]`).
     - If the target **matches**, the search is successful; **return** the index `pos`.
     - If the target is **less**, adjust the search interval to the **left** by setting `high = pos - 1`.
     - If the target is **greater**, adjust the search interval to the **right** by setting `low = pos + 1`.
4. Repeat the previous steps until the target element is found or the search interval is empty.
5. If the target element is not found, return an indication of failure.



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
Will be Updated in the Future...



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
- **"The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd Edition)** — by Donald Ervin Knuth
  - Section 6.2.1: Searching an Ordered Table

---  
&#127760; **Web-Resources:**  
- [Interpolation search](https://en.wikipedia.org/wiki/Interpolation_search) (Wikipedia)
- [Interpolation search vs Binary search](https://www.geeksforgeeks.org/g-fact-84/)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)