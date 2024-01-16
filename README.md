# Push Swap
Because Swap push was not enough

## Summary:

This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

# Learning how to use Stacks

The exercise asks to build a program that sorts the elements in a Stack of N elements (0 to 1000 or more?)

For this exercises 2 stacks are given, a Stack A and a Stack B. The Stack A is full and initialised based on the user input while B is a stack of the same dimensions, but empty. Stack B is to be used for convenience.

Fix output </br>
| 1 |
| 2 |
| 3 |
| 4 |
| 5 |
| 6 |
| 7 |
| 8 |
| Stack A | Stack B

The task is to swap the elements in the Stack in the minimum amount of steps possible.

# Actions allowed

* Swap: swap the position of the two elements on top of the list. This can be done for Stack A, Stack B or both at the same time;
* Rotate up: The first element of the stack becomes the last and all the others are pushed one place up. This can be done for Stack A, Stack B or both at the same time;
* Rotate down: The last element of the stack becomes the first one and all the others are pushed down a position. This can be done for Stack A, Stack B or both at the same time;
* Change of stack: Move the top element of Stack A to the top of Stack B or viceversa.

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
* Two moves - 3 Cases: (Rotate Down + Up is stupid)
    * "1 4 2 3" -> Swap + Rotate Up
    * "3 4 1 2" -> Rotate Down x2 (Or Up x2)
    * "3 2 4 1" -> Swap + Rotate Down
* Three moves - 7+ Cases
    * "1 3 2 4" -> Rotate Down + Swap + Rotate Up
    * "4 3 1 2" -> Swap + Rotate Down x2
    * "4 2 3 1" -> Rotate Up + Swap + Rotate Down
    * "3 1 4 2" -> Rotate Up + Swap + Rotate Up
    * "2 4 1 3" -> Rotate Down + Swap + Rotate Down
    * "2 3 1 4" -> Swap -> Rotate Down -> Swap
    * "3 1 4 2" -> Swap -> Rotate Up -> Swap // Same as previous
    * 3 4 2 1 -> Down 2x + Swap
* Four moves - :
    * 4 3 2 1 -> Swap + Rotate Up x2 + Swap
    * 2 4 3 1 -> Up + Swap + Up 2x
    * 3 1 2 4 -> Down -> Swap -> Up 2x

Combination not considered:
* 1 2 4 3
* 1 3 4 2
* 1 4 3 2
* 2 1 4 3
* 3 2 1 4
* 4 1 3 2
* 4 2 1 3

MOving from Stack A to B and back requires that at least two elements are moved back and forth and that at least an operation is made.
Moving two elements may account as a Rotation Up in Stack A as well, But at least 5 moves should be considered

> Stupid moves: 
> * Double swap
> * Rotate Up + Rotate Down
> Simmetries:
> * Rotate Up x2 == Rotate Down x2

### 5 Elements

Nice question! But we know there are 120 combinations possible!
