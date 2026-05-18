*This project has been created as part of the 42 curriculum abrunjes*
- [Description](#description)
	- [Rules](#rules)
	- [Data structures](#data-structures)
	- [Algorithm](#algorithm)
- [Instructions](#instructions)
- [Resources](#resources)

# Description
In this project I created a program `push_swap` which sorts a list of unique integers into ascending order subject to rules below. The program returns the operations in the order they were implemented. I used a simple 'K-Sort' or 'Butterfly Sort' as I called it. Further explanation below.

## Rules
We have two stacks, `stack_a` and `stack_b`. At the beginning, `stack_a` contains the unsorted list of integers, and `stack_b` is empty. The goal is to implement an algorithm (or a combination of algorithms) to sort the list using only the operations at our disposal. The operations used to sort the numbers are printed in order to stdout.

### Operations
Swap first two elements of:
- sa - stack_a
- sb - stack_b
- ss - both stacks <br>

Push element from one stack to another:
- pa - stack_b to stack_a 
- pb - stack_a to stack_b <br>

Rotate upwards (top of stack goes to bottom):
- ra - stack_a
- rb - stack_b 
- rr - both  stacks <br>

Rotate downwards (bottom of stack goes to top):
- rra - stack_a
- rrb - stack_b 
- rrr - both  stacks <br>

### Valid Inputs

The data parsed to the programe must be valid or `Error` and a new line is printed to stderr and the program doesn't run. Inputs must be integer values not exceeding the range of int type. Inputs cannot include letters. For example `./push_swap one 2 3` returns error.

### Example with valid inputs

`./push_swap 4 3 1 2`

#### Initial State

| Stack A | Stack B |
| :--- | :--- |
| 4 (top) | |
| 3 | |
| 1 | |
| 2 | |

#### After: pb
| Stack A | Stack B |
| :--- | :--- |
| 3 | 4 |
| 1 | |
| 2 | |

#### After: ra
| Stack A | Stack B |
| :--- | :--- |
| 1 | 4 |
| 2 | |
| 3 | |

#### After: pa
| Stack A | Stack B |
| :-| :- |
| 4 | |
| 1 | |
| 2 | |
| 3 | |

#### Final State (After: ra)
| Stack A | Stack B |
| :--- | :--- |
| 1 | |
| 2 | |
| 3 | |
| 4 | |


## Data structures
The program uses interconnected stucts to manages the stacks and operations. They are:
1. `t_node` which is our double linked list node used to create stacks. Contains the number and it's index and pointers to previous and next node.
2. `t_ps` program state - contains the stacks, the operation list, the size of both stacks, a counter for the operations and total number of inputs.
   
   
In order to have a better grasp of complex data structures, I decided that my stacks would be initialised as **circular doubly-linked lists**. This make the code look messy at points but the process of creating, adding, removing, rotating and swapping was good fun and an important learning curve. Of course with a circular linked list, rotations are very simple (move head back or forward) whilst the swaps are more like doing surgery on a mouse. <br>


## Algorithm

I started ambitiously wanting to do a recursive two pivot quick sort. However, between starting and finishing this project 42 London closed down, I moved to Paris and didn't touch code for 6 weeks whilst doing so. As such I have unitlised a simple yet efficient algorithm, the 'Butterfly Sort'.

A chunk/window is calculated based on the total amount of numbers ($x$) we are sorting. 

```math 
Window~Size =1.4~\sqrt{x}
```
We iterate through the list one at a time with a counter starting at 0.
* If the current element's index is smaller than the counter we **pb** and **rb**.
* If the index is between the sliding window we **pb**
* If it is large than the window we just **ra**. 

This pushes smaller numbers toward the bottom of `stack_b` while larger ones stay near the top. As the counter increases, a **K-like or Butterfly wing shape** forms in `stack_b`. 

The beauty of this structure is that when it is time to push elements back to `stack_a`, the exact numbers we need are always sitting very close to either the top or bottom edge of `stack_b`. The program checks whether the required element is in the top or bottom half, applies the minimal amount of rotations (`rb` or `rrb`) to bring it to the top, and pushes it back home to `stack_a`.

### Performance & Benchmarks

The program has been optimised to comfortably pass requirements.

| Number of Integers | 42 Benchmark | My Performance | Points Awarded |
| :--- | :--- | :--- | :--- |
| **3 values** | Max 3 operations | $\le 2$ | 5 / 5 |
| **5 values** | Max 12 operations | $\le 11$| 5 / 5 |
| **100 values** | Less than 700 ops | $\le 613$ | 5 / 5 (Max Points) |
| **500 values** | Less than 5500 ops | $\le 5260$ | 5 / 5 (Max Points) |

_Note: Performance averages are calculated using external bash script._
# Instructions

To create program: `make` and then to run it with `./push_swap <your inputs>`.

To run **z** numbers between **x** and **y** use:
```
ARG=$(shuf -i x-y -n z | tr '\n' ' ') ; ./push_swap $ARG | wc -l
```
The output is the number of operations used to sort the list.
# Resources


1. [Doubly linked list](https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/)
2.  [Makefile Tutorial](https://github.com/gleal42/Makefile-Tutorial)
3. [GH_Push_swap - madebypixel02](https://github.com/madebypixel02/push_swap)
4. [GH_Push_swap - shinckel](https://github.com/shinckel/push_swap)
5. [GH - K Sort - Azer Sioud](https://github.com/AzerSD/ksort-push_swap/tree/master/src)
6.  [Medium Post - K Sort - Sylvain Maitre](https://medium.com/@brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376)
7. [Medium Post - Recursive Algo - Ulysse Gerkens](https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0)
8. [Medium Post - Set Up - Jamie Dawson](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
9. [Visualiser - Niimphu](https://github.com/Niimphu/push_swap_visualiser)

AI Usage - AI was used to clarify concepts, explore algorithms and help with planning execution. It was never used to generate code.
