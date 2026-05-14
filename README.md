*This project has been created as part of the 42 curriculum abrunjes*
- [Decription](#decription)
	- [Rules](#rules)
		- [Operations](#operations)
		- [Valid Inputs](#valid-inputs)
		- [Example with valid inputs](#example-with-valid-inputs)
			- [Initial State](#initial-state)
			- [After: pb](#after-pb)
			- [After: ra](#after-ra)
			- [After: pa](#after-pa)
			- [Final State (After: ra)](#final-state-after-ra)
	- [Data stuctures](#data-stuctures)
	- [Algorithm](#algorithm)
	- [Pseudocode](#pseudocode)
- [Instructions](#instructions)
- [Resources](#resources)
- [Notes](#notes)

# Decription
In this project I created a programe `push_swap` which sorts a list of unique integers into accending order, subject to rules below. The programme returns the operations in the order they were done in.  I implement an adapted two-pivot quicksort alrogrithm to do this.

## Rules
We have two stacks, `stack_a` and `stack_b`. At the beginning, `stack_a` contains the unsorted list of integers, and `stack_b` is empty. The goal is to implement an algorithm (or a combination of algorithms) to sort the list using only the operations at our disposal.The operations used to sort the numbers are printed in order to stdout.

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
- ra - stack_b 
- rr - both  stacks <br>

Rotate downwards (bottom of stack goes to top):
- rra - stack_a
- rra - stack_b 
- rrr - both  stacks <br>

### Valid Inputs

The data parsed to the programe must be valid or `Error\n` is printed to stderr and the programme doens't run. Inputs must be integer values not exceding the range of int type. Inputs can't have any letters in nor be typed words.

### Example with valid inputs

`./push_swap 3 2 1 2`

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


## Data stuctures
The programme uses interconnected stuctss to manange the stacks and operations. They are:
1. `t_node` which is our double linked list node used to create stacks. Contains the number and it's index and pointers to previous and next node.
2. `t_ps` programme state - contains the stacks, the operation list, the size of both stacks, a counter for the operations and total number of inputs.
   
   
In order to have a better grasp of complex data structures, I decided that my stacks would be initialised as **circular doubly-linked lists**. This make the code look messy at points but the process of creating, adding, removing, rotating and swapping was good fun and an important learning curve. Of course with a circular linked list, rotations are very simple (move head back or forward) whilse the swaps are more like doing surgery on a mouse. <br>


## Algorithm

I started ambitiously was wanting to do a recursive two pivot quick sort. But between starting and finishing this project 42 London closed down, I moved to Paris and didn't touch code for 6 weeks whilst doing so. As such I have a simple yet very efficient algorithm. 

A window is calculated based on the numbers of numbers we are sorting. We iterate through the list one at a time with a counter starting at 0. If the current element is smaller than the counter we **pb** and **rb**. If it's between the sliding window we **pb**. If it's bigger than the window we just **ra**. 

This means the smallest are pushed to the bottom of the staack whilst the largest stay at the top. As we iterate through the list the what is small or large increases so a 'K' like shape appears in stack_b. The beauty of this is when sending back to stack_a the numbers we need are closest to the edge and so minimal rotations required to send them back.

This second sweep back to stavkk_s         
## Pseudocode
1. Initilise stacks - stack_a with unsorted list and stack_b null
2. 
# Instructions
 - Eval time!

# Resources

1. [On Sorting with a Network of Two Stacks](https://drops.dagstuhl.de/storage/01oasics/oasics-vol075-atmos2019/OASIcs.ATMOS.2019.3/OASIcs.ATMOS.2019.3.pdf)
4. [Doubly linked list](https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/)
5. [Makefile Tutorial](https://github.com/gleal42/Makefile-Tutorial)
6. [GH_Push_swap - madebypixel02](https://github.com/madebypixel02/push_swap)
7. [GH_Push_swap - shinckel](https://github.com/shinckel/push_swap)
8. [Medium Post - Ulysse Gerkens](https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0)
3. [Medium Post - Jamie Dawson](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
2. [Medium Post - Oduwole Dare](https://medium.com/@oduwoledare/42-push-swap-explained-psuedocodes-ba8108339556)
	

# Notes
- set up linked list and operations - overview of a few approaches
- use inbuild linked lists .. from Andrei ... man k queue - - all inbuilt to build framework
- 