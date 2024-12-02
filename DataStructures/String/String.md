# &#128209; Table of Contents
- [💡 Overview](#-overview)
  - [Essential Terminology](#essential-terminology)
  - [Core Mechanics](#core-mechanics)
  - [Container Methods](#container-methods)
- [💻 Implementation](#-implementation)
  - [Design Decisions](#design-decisions)
  - [Container Implementation](#container-implementation)
  - [Iterator Implementation](#iterator-implementation)
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
**String** refers to both an abstract data structure and a concrete container, embodying a sequence of characters designed for storing and manipulating text or symbolic data. The term _«string»_ comes from its resemblance to a string of characters, much like beads strung together on a physical string. Knowledge and understanding of it lay a solid foundation in designing data structures and optimizing their application.
<p align="center"><img src="./Images/String.png"/></p>


## Essential Terminology
- **Abstract Data Structure** — is a theoretical model that defines a set of operations and guarantees for organizing and manipulating data, independent of memory organization or specific implementation details.
  - **Data Structure** — is a theoretical model of data organization in memory, used to design containers in an efficient or specific ways.
  - **Container** — is a concrete implementation, used to manage actual data through specific operations. Containers are primarily defined by the operations and guarantees they provide, which can originate from the data structure itself or from an abstract data structure. As long as those guarantees are fulfilled, the underlying model can be modified or replaced.
- **String** — refers to both an abstract data structure and a concrete container, embodying a sequence of characters designed for storing and manipulating text or symbolic data. This dual nature arises from its ability to represent a conceptual guarantee of functionality while being implemented in diverse ways.
  - **Character** — the smallest unit of a text that has semantic value.
  - **Null-Terminator** — is a special character «`\0`» used in C-style strings to indicate the end of the string for functions. String containers don't require it because they keep track of the string's length internally; however, it can be added to maintain compatibility when necessary.



## Core Mechanics
In programming, there was a need to compactly represent characters, such as letters, digits, and symbols, in a way that both humans and computers could interpret. A character is essentially the smallest unit of text, and strings are sequences of these characters grouped together to represent text. Characters are mapped to binary representations (sequence of bits) via **character encodings**, allowing computers to store and process text in a machine-readable format, while humans see it as readable text. 

Different mappings exist to efficiently represent diverse characters, symbols, and languages, while balancing memory usage, compatibility, and performance across systems. While fixed-length encodings allow constant-time indexing $O(1)$, variable-length encodings require traversing the string to decode each character, resulting in $O(n)$ complexity for accessing characters by index. 

**Some Popular Encodings:**
- **ASCII (American Standard Code for Information Interchange)** — is a standard for encoding basic English text and control symbols.
  - **ASCII** — is a fixed-length encoding, which uses $7$ bits per character.
  - **Extended ASCII** — is fixed-length encoding, which uses $8$ bits per character.
  <p align="center"><img src="./Images/EncodingASCII.png"/></p>
- **UTF (Unicode Transformation Format)** — is a universal standard designed to represent characters from all languages, symbols, and emojis, using multibyte encodings that allow a single character to occupy more than one byte.
  - **UTF-8** — is a variable-length encoding, which uses $1$ to $4$ bytes per character.
  - **UTF-16** — is variable-length encoding, which uses $2$ bytes for most characters, with some requiring $4$ bytes.
  - **UTF-32** — is fixed-length encoding, which uses $4$ bytes per character.
  <p align="center"><img src="./Images/EncodingUTF.png"/></p>



## Container Methods
Currently in Progress...



# &#x1F4BB; Implementation 
Currently in Progress...


## Design Decisions
Currently in Progress...


## Container Implementation
Currently in Progress...


## Iterator Implementation
Currently in Progress...


# &#128202; Analysis
Currently in Progress...


## Characteristics
Currently in Progress...


## Trade-Offs
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
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../#-contacts).



# &#128591; Credits
&#128218; **Books:**
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 3.6: Strings

---
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 8: Strings

--- 
&#127760; **Web-Resources:**
- [String (computer science)](https://en.wikipedia.org/wiki/String_(computer_science)) (Wikipedia)
- [Character (computing)](https://en.wikipedia.org/wiki/Character_(computing)) (Wikipedia)
- [Character encoding](https://en.wikipedia.org/wiki/Character_encoding) (Wikipedia)
- [ASCII Table](https://www.ascii-code.com)
- [UTF-8 encoding table and Unicode characters](https://www.utf8-chartable.de)
- [What is character encoding? Exporing Unicode, UTF8, ASCII, and more](https://youtu.be/4i0beu7qct0?si=b6blUlFWpxhDletM) (Video)
- [Writing an ITERATOR in C++](https://www.youtube.com/watch?app=desktop&v=F9eDv-YIOQ0) (Video)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)