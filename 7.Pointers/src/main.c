/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice pointers.
 * @details This program calls a function to multiply integers. However, this
 * function is not defined yet, you must define it. Similarly for a factorial
 * function that you must define.
 * To see the compilation and execution commands, refer to the first exercise.
 * You are strongly encouraged to type them yourself, rather than copy/pasting,
 * as it may help you memorise.
 **/
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Do not worry about understanding the "int main(...)" line for now. You
 * will learn it in due time, in a different exercise.
 */
int main(int argc, char* argv[])
{
    // Declare a pointer variable 'pointer_a' that points to variable 'a'.
    int a = 123;
    int* pointer_a = &a;
    printf("Value of variable 'a' = %d, address of variable 'a' = %p.\n", a, pointer_a);

    /*
     * Implement a function 'multiply_by_2' that takes a pointer on an integer
     * and update the value of the variable pointed by multiplying it by 2.
     */
    multiply_by_2(pointer_a);
    printf("New value of variable 'a' is %d.\n", a);

    return EXIT_SUCCESS;
}