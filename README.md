*This project has been created as part of the 42 curriculum by rcarmo-n.*

## Description

push_swap is a sorting project that focuses on algorithmic optimization using a
restricted set of operations. The goal is to sort a stack of integers in ascending
order with the lowest possible number of moves.

This implementation is based on the Turk algorithm, which relies on calculating
target positions and move costs to efficiently transfer elements between two stacks.

The bonus part of the project consists on creating a checker, a program that will 
check weather the developed push_swap does order the list or not.

## Instructions

### Compilation

    make
    make bonus

### Execution

    ./push_swap <numbers>
    ./push_swap <numbers> | ./checker <numbers>

Example:

    ./push_swap 3 2 5 1 4
    ./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4 

The main program outputs the list of operations to standard output.
The bonus program outputs a message that tells if the previous program was successful.

### Cleanup

    make clean
    make fclean

## Resources

A video that explains how the Turk algorithm works.
Used AI to:
- Discuss about the Turk algorithm and possible ways to improve it.
- Assist with debugging when the code got to extended.
