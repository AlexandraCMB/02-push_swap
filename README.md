*This project has been created as part of the 42 curriculum abrunjes*
- [Decription](#decription)
	- [Rules](#rules)
		- [Operations](#operations)
		- [Example](#example)
	- [Data stuctures](#data-stuctures)
	- [Algorithm](#algorithm)
	- [Pseudocode](#pseudocode)
- [Instructions](#instructions)
- [Resources](#resources)
- [Notes](#notes)

# Decription
In this project I created a programe `push_swap` which sorts a list of unique integers into accending order, subject to rules below. The programme returns the operations in the order they were done in.  I implement an adapted two-pivot quicksort alrogrithm to do this.

## Rules
We have two stacks, `stack_a` and `stack_b`. At the beginning, `stack_a` contains the unsorted list of integers, and `stack_b` is empty. The goal is to implement an algorithm (or a combination of algorithms) to sort the list using only the operations at our disposal.

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
 
### Example

 ```
./push_swap 4 3 1 2
pb
ra
pa
ra
```

Initial state (left-right, top-bottom):
```
	stack_a	| 4 3 1 2
	stack_b | -
```
After 'pb';
```
	stack_a	| 3 1 2
	stack_b | 4
```
After 'ra';
```
	stack_a	| 1 2 3
	stack_b | 4
```
After 'pb';
```
	stack_a	| 4 1 2 3
	stack_b | -
```
Final state, after 'ra':
```
	stack_a	| 1 2 3 4
	stack_b | -
```


## Data stuctures
The programme uses interconnected sturcys to manange the stacks and operations. They are:
1. `t_node` which is our double linked list node used to create stacks.
2. `t_stack` stack wrapper containts stack and it's length.
3. `t_ps` programme state - containts following t_stacks (ie stacks and lengths): stack_a, stack_b, operations.
   
   
In order to have a better grasp of complex data structures, I decided that my stacks would be initialised as **circular doubly-linked lists**. This make the code look messy at points but the process of creating, adding, removing, rotating and swapping was good fun and an important learning curve. Of course with a circular linked list, rotations are very simple (move head back or forward) whilse the swaps are more like doing surgery on a mouse. <br>


## Algorithm


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