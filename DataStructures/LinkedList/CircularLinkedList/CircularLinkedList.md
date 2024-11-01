# &#128209; Table of Contents
- [💡 Overview](#-overview)
	- [Important Details](#important-details)
	- [Container Methods](#container-methods)
- [💻 Implementation](#-implementation)
	- [Design Decisions](#design-decisions)
	- [Iterator Implementation](#iterator-implementation)
	- [Container Implementation](#container-implementation)
- [📊 Analysis](#-analysis)
	- [Characteristics](#characteristics)
	- [Trade-Offs](#trade-offs)
- [📝 Application](#-application)
	- [Common Use Cases](#common-use-cases)
	- [Some Practical Problems](#some-practical-problems)
- [🕙 Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
**Circular Linked Lists** are implementations of a linked list where the last node in sequence points back to the first node, allowing for continuous traversal from any node. The name comes from the fact that each node eventually links back to itself, creating a circular sequence. Knowledge and understanding of it lay a solid foundation in designing data structures and optimizing their application.
<p align="center"><img src="./Images/CircularLinkedList.png"/></p>


## Important Details
1. **Node Composition** — each node in a circular linked list contains a data element and pointers to other nodes just like regular linked lists. In a circular singly linked list, each node has a pointer to the next node, while in a circular doubly linked list, each node has pointers to both the next and previous nodes. 

2. **Continuous Traversal** — circular linked lists allow continuous traversal, as the last node loops back to the head. Starting from any node, traversing will eventually lead back to the same node, making these lists particularly useful for applications that require round-robin access or repeated cycles.

3. **End of List** — since circular linked lists have no `nullptr` to mark the end, identifying the beginning or completing a traversal requires special handling. Typically, this is done by keeping track of the starting node and stopping once we loop back to it.


## Container Methods
When working with a circular linked list, it’s important to note that there is no universal standard defining its operations or implementation guidelines. The design and functionality of a circular linked list container can vary based on factors like programming language, library goals, and performance needs. Although circular linked lists are not natively available in the C++ Standard Library, they can be adapted from `std::forward_list` or `std::list`. Additionally, Boost provides an existing circular data structure, `boost::circular_buffer`, which may meet similar needs.

Circular linked list operations are mostly similar to those of [singly](https://github.com/vezzolter/DSA/blob/split-list/DataStructures/LinkedList/SinglyLinkedList/SinglyLinkedList.md#-overview) or [doubly](https://github.com/vezzolter/DSA/blob/split-list/DataStructures/LinkedList/DoublyLinkedList/DoublyLinkedList.md#-overview) linked lists, but with one key difference: the last node links back to the first, forming a continuous loop with no `nullptr` at the end. This circular structure removes the need for a `nullptr` check at the list's end, meaning traversal or modification operations that typically stop at the last node will continue looping to the head. To avoid infinite loops, implementations often track the starting node or count traversed elements, stopping once all nodes have been visited. In cases requiring multiple iterations over the list, careful control of the iteration process is essential to prevent unintended cycling.


# &#x1F4BB; Implementation 
Currently in Progress...


##  Design Decisions
Currently in Progress...


##  Iterator Implementation
Currently in Progress...


##  Container Implementation
Currently in Progress...



# &#128202; Analysis
Currently in Progress...


## Characteristics
Currently in Progress...


## Trade-Offs
Currently in Progress...



# &#128221; Application
Understanding some of the most well-known use cases of a container is crucial for grasping its practical relevance and potential impact in real-world scenarios. Additionally, familiarizing oneself with common practical problems and practicing their solutions ensures that you remember the essential details and develop a deep, intuitive understanding of the functionality and limitations.


## Common Use Cases
As mentioned in the [LinkedList.md](https://github.com/vezzolter/DSA/blob/split-list/DataStructures/LinkedList/LinkedList.md), the concrete use cases (and anti use cases) directly derive from the advantages (and disadvantages) of the container, so there is no need for this sort of rephrasing. Since circular linked lists share the foundational principles of the general concept of linked lists, their common usage is best described in the [linked lists respective section](../LinkedList.md#-application).


## Some Practical Problems
Since circular linked lists share the foundational principles of the general concept of linked lists, their common problems is best described in the [linked lists respective section](../LinkedList.md#-application).



# &#x1F559; Origins
Since circular linked lists share the foundational principles of the general concept of linked lists, their historical development is best described in the [linked lists respective section](../LinkedList.md#-application).



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../../#-contacts).



# &#128591; Credits
Since circular linked lists share the foundational principles of the general concept of linked lists, the resources that contributed to their understanding are best described in the [linked lists credits section](../LinkedList.md#-credits).



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)