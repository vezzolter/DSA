# &#128209; Table of Contents
- [💡 What is Fibonacci Sequence](#-what-is-fibonacci-sequence)
- [💻 Implementation of Fibonacci Sequence](#-implementation-of-fibonacci-sequence)
  - [Iteration vs Recursion](#iteration-vs-recursion)
  - [Detailed Overview](#detailed-overview)
  - [Call Stack Interaction](#call-stack-interaction)
- [📝 Application of Fibonacci Sequence](#-application-of-fibonacci-sequence)
  - [Basic Example](#basic-example)
  - [Practical Example](#practical-example)
- [⏳ Historical Notes](#-historical-notes)
- [🤝 Contributing](#-contributing)
- [📧 Contact Information](#-contact-information)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; What is Fibonacci Sequence
The Fibonacci sequence is one of the simplest and earliest known sequences defined by a recurrence relation, which stands among the fundamental mathematical patterns with widespread applications in algorithms and data structures. Knowledge of the Fibonacci sequence enhances problem-solving skills and lays the foundation for tackling more complex mathematical and computational challenges.

---

**Fibonacci Seqence** — is a series of numbers, where each number is the sum of the two preceding numbers. Traditionally starts with $0$ and $1$ (but can start with different initial values), forming following sequence: $0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 89, 144, 233, 377$ and so on. The terms of this sequence are known as **Fibonacci numbers** and can be denoted as $F_n$, therefore general formula can be recursively written as $F_n = F_{n-1} + F_{n-2}$.

The other related concept to the Fibonacci Sequence is **golden ratio** ($\Phi = \frac{1+\sqrt{5}}{2} ≈ 1.61803398875$) — is an irrational number, which appears between ratio of bigger and smaller value, holding property: $\frac{bigger+smaller}{bigger} = \frac{bigger}{smaller} = \phi$

**Relation Between Golden Ratio and Fibonacci Sequence:**
- Ratio of any two consecutive Fibonacci numbers, gets closer to the golden ratio ($\Phi$) as the numbers get larger,  
e.g. $\frac{13}{8} = 1.625$; $\frac{233}{144} = 1.61805$

- Any Fibonacci number can be approximately calculated by multiplying with golden ration,  
e.g. $5×1.618034=8.09017$.

- Any Fibonacci number can be precisely calculated by using Binet's formula $F_n = \frac{\phi^n-(1-\phi)^n}{\sqrt{5}}$,  
e.g. $F_8 = \frac{\phi^8-(1-\phi)^8}{\sqrt{5}} = \frac{\big(\frac{1+\sqrt{5}}{2}\big)^8-\big(1-\frac{1+\sqrt{5}}{2}\big)^8}{\sqrt{5}}=\frac{\frac{(1+\sqrt{5})^8}{2^8}-\frac{(1-\sqrt{5})^8}{2^8}}{\sqrt{5}}=\frac{(1+\sqrt{5})^8-(1-\sqrt{5})^8}{2^8\sqrt{5}}=\frac{\big((1+\sqrt{5})^8-(1-\sqrt{5})^8\big)\sqrt{5}}{1280}=$  
$=\frac{\big(6016+2688\sqrt{5}-6016+2688\sqrt{5} \big)\sqrt{5}}{1280}=\frac{(5376\sqrt{5})\sqrt{5}}{1280}=\frac{26880}{1280}=21$

---

While there are numerous fascinating properties of the Fibonacci sequence yet to be explored (such as terms below zero, alternation of even and odd numbers, 1/89, etc), for the scope of this subsection in the repository, the knowledge of the above would be sufficient to implement and comprehend the key ideas.



# &#x1F4BB; Implementation of Fibonacci Sequence
**Idea**  
Currently in progress...

## Iteration vs Recursion
Currently in progress...

## Detailed Overview
Currently in progress...

## Call Stack Interaction
Currently in progress...



# &#128221; Application of Fibonacci Sequence
Currently in progress...


## Basic Example
Currently in progress...


## Practical Example
Currently in progress...



# &#x23F3; Historical Notes
The first mention of sequence was around 200 BC done by Indian mathematician **Acharya Pingala** in his work on Sanskrit prosody. Though Pingala did not employ the modern notation or terminology, he comprehended the fundamental nature of the sequence and its correlation with the golden ratio. Later those series were mentioned by other indian mathematicians such as **Bharata Muni** and **Virahanka**,**Gopala**.

Centuries later, in 1170, an Italian mathematician named **Leonardo** was born in Pisa. As a teenager, he accompanied his father to work in the port city of Bugia, present-day Algeria, where he represented Italian merchants. In Bugia, Leonardo encountered numerous merchants using Hindi and Arab numerals in their calculations. Intrigued by the efficiency and simplicity of this numerical system, which contrasted with the widely used Roman numerals in Europe, Leonardo began to learn and appreciate the advantages of it.

Over the course of his life, Leonardo interacted with numerous merchants, absorbing knowledge from them and translating his insights into several books. These works covered the advantages of Hindu numerals, delved into various mathematical problems, explored geometry and delved into number theory. However, his most renowned contribution is arguably found in "Liber Abaci" (1202). In this book, Leonardo explained how adopting this numerical system could greatly simplify business transactions.

Besides popularizing the Hindu-Arabic numerical system, he introduced the discussed sequence while addressing a challenge linked to the proliferation of rabbit populations. Notably, he did not explicitly named it the "Fibonacci sequence." It was only later, as his books gained popularity, that the name "Fibonacci", derived from "filius Bonacci" (roughly meaning "son of the Bonacci family"), was coined by Franco-Italian historian Guillaume Libri in 1838 to distinguish him from other Leonardo.



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128231; Contact Information
For contact details and additional information, please refer to the [root directory's contact information section](../../../#-contact-information).



# &#128591; Credits
&#128218; **Books:**
- **"Introduction to Algorithms"** — by CLRS
  - Appendix C: Counting and Probability.

&#127891;**Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/?LSNPUBID=JVFxdTr9V80&ranEAID%3B=JVFxdTr9V80&ranMID%3B=39197&ranSiteID%3B=JVFxdTr9V80-_3GVcwGZFWT4XsSuZYrgGA&utm_source=adwords&utm_medium=udemyads&utm_campaign=DSA_Catchall_la.EN_cc.ROW&utm_content=deal4584&utm_term=_._ag_88010211481_._ad_535397282064_._kw__._de_c_._dm__._pl__._ti_dsa-406594358574_._li_9061020_._pd__._&matchtype=&gad_source=1&gclid=CjwKCAiA3aeqBhBzEiwAxFiOBgRFL7RkV-WJI9tPKml75et478Ai5oJigSKAivJ2txZ9Jhi0mhsTdxoC_foQAvD_BwE) on Udemy
   - Section 5: Recursion

&#127760;**Web-Resources:**
- [Fibonacci Sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence) (Wikipedia)
- [Fibonacci Sequence](https://www.cuemath.com/numbers/fibonacci-sequence/)
- [What is the Fibonacci sequence?](https://www.livescience.com/37470-fibonacci-sequence.html)
- [Golden ratio](https://en.wikipedia.org/wiki/Golden_ratio) (Wikipedia)
- [Golden ratio: A beginner's guide](https://www.adobe.com/creativecloud/design/discover/golden-ratio.html)
- [Binet's Formula](https://artofproblemsolving.com/wiki/index.php/Binet%27s_Formula)
- [The so-called fibonacci numbers in ancient and medieval India](https://www.sciencedirect.com/science/article/pii/0315086085900217?via%3Dihub) (Research)
- [Indian origins of the Fibonacci sequence](https://trueindologytwitter.wordpress.com/2020/03/31/indian-origins-of-the-fibonacci-sequence/)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)