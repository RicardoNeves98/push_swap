*This project has been created as part of the 42 curriculum by rcarmo-n.*

## Description

push_swap is a sorting project that focuses on algorithmic optimization using a
restricted set of operations. The goal is to sort a stack of integers in ascending
order with the lowest possible number of moves.

This implementation is based on the Turk algorithm, which relies on calculating
target positions and move costs to efficiently transfer elements between two stacks
(A and B) until the stack is sorted.

## Instructions

### Compilation

    make

### Execution

    ./push_swap <numbers>

Example:

    ./push_swap 3 2 5 1 4

The program outputs the list of operations to standard output.

### Cleanup

    make fclean

## Resources

- 42 subject PDF: push_swap
- Turk algorithm for push_swap
- Stack-based sorting strategies
- Algorithm complexity (Big-O notation)

## Use of AI

AI was used to:
- Discuss and understand the Turk algorithm
- Explore possible optimizations and improvements
- Assist with debugging and problem-solving
