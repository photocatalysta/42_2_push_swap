# Push Swap
Because Swap_push isn’t as natural

## Summary

This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you will have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

# Learning how to use Stacks

The exercise asks to build a program that sorts the elements in a Stack of N elements (0 to 1000 or more?)

For this exercises 2 stacks are given, a Stack A and a Stack B. The Stack A is full and initialised based on the user input while B is a stack of the same dimensions, but empty. Stack B is to be used for convenience.

Fix output </br>
| 1 | </br>
| 2 | </br>
| 3 | </br>
| 4 | </br>
| 5 | </br>
| 6 | </br>
| 7 | </br>
| 8 | </br>
| Stack A | Stack B

The task is to swap the elements in the Stack in the minimum amount of steps possible.

# Actions allowed

At the beginning:

* The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
* The stack b is empty.

The goal is to sort in ascending order numbers into stack a.

To do so you have the following operations at your disposal:

* Swap: swap the position of the two elements on top of the list. This can be done for Stack A, Stack B or both at the same time;
  * `sa` (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
  * `sb` (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
  * `ss` : sa and sb at the same time.

* Push stack: Move the top element of Stack A to the top of Stack B or viceversa.
  * `pb` (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  * `pa` (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

* Rotate (Up): The first element of the stack becomes the last and all the others are pushed one place up. This can be done for Stack A, Stack B or both at the same time;
  * `ra` (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
  * `rb` (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
  * `rr` : ra and rb at the same time.

* Rotate reverse (Down): The last element of the stack becomes the first one and all the others are pushed down a position. This can be done for Stack A, Stack B or both at the same time;
  * `rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
  * `rrb` (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
  * `rrr` : rra and rrb at the same time.

# The algorithm to be used

## Simple cases

### 0 - 1 elements

The stack is already ordered. THe output is created accordingly to the request of the exercise.

### 2 Elements (2! = 2 Combo)

They are either ordered, or they are not. Both a swap or a rotation of the elements solves the disordered case

### 3 Elements (3! = 6 Combos)

Possible cases:

* Already good - 1 case:
    * "1 2 3";
* One move - 3 Cases:
    * "2 1 3" -> Swap top;
    * "3 1 2" -> Rotate Up
    * "2 3 1" -> Rotate Down
* Two moves - 2 Cases:
    * "3 2 1" -> Swap + Rotate down
    * "1 3 2" -> Rotate down + Swap

### 4 Elements - 24 Cases

* Already good - 1 case:
    * "1 2 3 4";
* One move - 3 Cases:
    * "2 1 3 4" -> Swap top;
    * "4 1 2 3" -> Rotate Up;
    * "2 3 4 1" -> Rotate Down;
* Two moves - 5 Cases: (Rotate Down + Up is stupid)
    * "1 4 2 3" -> Swap + Rotate Up
    * "1 3 4 2" -> Rotate Down + Swap
    * "3 4 1 2" -> Rotate Down x2 (Or Up x2)
    * "3 2 4 1" -> Swap + Rotate Down
    * "4 2 1 3" -> Rotate Up + Swap
* Three moves - 7+ Cases
    * "1 3 2 4" -> Rotate Down + Swap + Rotate Up
    * "4 3 1 2" -> Swap + Rotate Down x2
    * "4 2 3 1" -> Rotate Up + Swap + Rotate Down
    * "3 1 4 2" -> Rotate Up + Swap + Rotate Up
    * "2 4 1 3" -> Rotate Down + Swap + Rotate Down
    * "2 3 1 4" -> Swap -> Rotate Down -> Swap
    * "3 1 4 2" -> Swap -> Rotate Up -> Swap // Same as previous
    * "3 4 2 1" -> Down 2x + Swap
* Four moves - :
    * "4 3 2 1" -> Swap + Rotate Up x2 + Swap
    * "2 4 3 1" -> Up + Swap + Up 2x
    * "3 1 2 4" -> Down -> Swap -> Up 2x
    * "3 2 1 4" : Swap -> 2314 - 3
    * "4 1 3 2" : Rotate Up -> 1324 - 3 / Rotate Down -> 2413 - 3
* Five moves - :
    * "1 2 4 3" : Rotate Up -> 2431 - 4 / Rotate Down -> 3124 - 4
    * "1 4 3 2" : Swap -> 4132 - 4 / Rotate Up -> 4321 - 4
    * "2 1 4 3" : Rotate Down -> 3214 - 4

Moving from Stack A to B and back requires that at least two elements are moved back and forth and that at least an operation is made.
Moving two elements may account as a Rotation Up in Stack A as well, But at least 5 moves should be considered

> Stupid moves:
>
> * Double swap
> * Rotate Up + Rotate Down
> Simmetries:
> * Rotate Up x2 == Rotate Down x2

### 5 Elements

Nice question! But we know there are 120 combinations possible! This is enough to just get going with a different approach...

Of the many different existent algorithms, many are based on either swapping elements based on the array position. For this excercise we could consider a simple bubble sort, although it would be a rather slow approach. We could as well do a merge sort and use the different stacks to lower the amount of calculations, however it would be limited to only two separation.

An algorithm that has so far found success is the radix sort. This algorithm tends to organise the stack starting from the units digit and moving towards the biggest digit. Approaching this from a computer perspective, the values can be simplified to their binary (base 2) representation and use bitwise logic to sort every digit in the two bins and reorganise it accordingly. The main drawback of this approach is that it will fail if it is used for negative values.

For the success of this exercise, the most important part is the final amount of actions achieved. The radix sort is fast enough that it will always achieve a good enough result. You can definitely do better! However, setting up a full data science project to always achieve the lowest amount of instructions may not be the wisest! Timeouts... Remember?

An example of radix sort with 6 numbers:

| Base 10 | 0 | 1 | 2 | 3 | 4 | 5 |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Base 2 | 000 | 001 | 010 | 011 | 100 | 101 |

Let's consider a random organisation and brute force the algorithm for 4 3 0 2 1 5

We will only move A elements with:
* R -> Rotation Up
* S -> Switch to B

1st iteration:

|  A  |  B  |    |  A  |  B  |    |  A  |  B  |
| :-: | :-: | -- | :-: | :-: | -- | :-: | :-: |
| 100 |  /  | -> |  /  |  /  | -> | 100 |  /  |
| 011 |  /  | -> |  /  |  /  | -> | 000 |  /  |
| 000 |  /  | -> |  /  |  /  | -> | 010 |  /  |
| 010 |  /  | -> | 101 | 100 | -> | 011 |  /  |
| 001 |  /  | -> | 001 | 000 | -> | 001 |  /  |
| 101 |  /  | -> | 011 | 010 | -> | 101 |  /  |

1st Part moves: RSRRSS
2nd Part: SSS

Given N elements, this would require initially N moves + N/2 for the step back

2nd iteration - Will be based on the second last digit:

|  A  |  B  |    |  A  |  B  |    |  A  |  B  |
| :-: | :-: | -- | :-: | :-: | -- | :-: | :-: |
| 100 |  /  | -> |  /  |  /  | -> | 101 |  /  |
| 000 |  /  | -> |  /  |  /  | -> | 001 |  /  |
| 010 |  /  | -> |  /  | 101 | -> | 000 |  /  |
| 011 |  /  | -> |  /  | 001 | -> | 100 |  /  |
| 001 |  /  | -> | 010 | 000 | -> | 010 |  /  |
| 101 |  /  | -> | 011 | 100 | -> | 011 |  /  |

1st Part moves: SSRRSS
2nd Part: SSSS

Although it may seem the use of 1 is advantageous, that would require to rotate the pile in order not to order the whole pile in descending order. That would be N moves for the second part as well.

3rd iteration - Will be based on the third last digit:

|  A  |  B  |    |  A  |  B  |    |  A  |  B  |
| :-: | :-: | -- | :-: | :-: | -- | :-: | :-: |
| 101 |  /  | -> |  /  |  /  | -> | 001 |  /  |
| 001 |  /  | -> |  /  |  /  | -> | 000 |  /  |
| 000 |  /  | -> |  /  | 010 | -> | 011 |  /  |
| 100 |  /  | -> |  /  | 011 | -> | 010 |  /  |
| 010 |  /  | -> | 101 | 000 | -> | 101 |  /  |
| 011 |  /  | -> | 100 | 001 | -> | 100 |  /  |

1st Part moves: SSRRSS
2nd Part: SSSS

* Total: 29 moves without swaps but Swap of AB + Swap A in the right moment and 31 moves is possible.
* Expected from Radix_Swap: 36;

From this we learnt that:
* Rotation is fundamental to ensure the order.
* We could Add A to B in the second iteration to save 2 moves and split from B to A the 1** in the 3rd
    * This is convinient only if N % $2^{move}$ is < $2^{move - 1}$ and N % $2^{move}$

## Check the actual case for the previous situation

Moving always ones to B leads to a reverted list:

|  A  |  A  |  A  |  A  |
| :-: | :-: | :-: | :-: |
| 100 | 011 | 011 | 101 |
| 011 | 001 | 010 | 100 |
| 000 | 101 | 001 | 011 |
| 010 | 100 | 101 | 010 |
| 001 | 000 | 100 | 001 |
| 101 | 010 | 000 | 000 |

--> This leads to a reverted list...

What about other strategies? Can you find faster ones?
