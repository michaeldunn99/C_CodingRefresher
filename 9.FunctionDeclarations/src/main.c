/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice the decoupling of function
 * declaration and definition.
 * To see the compilation and execution commands, refer to the first exercise.
 * You are strongly encouraged to type them yourself, rather than copy/pasting,
 * as it may help you memorise.
 **/
#include <stdio.h>
#include <stdlib.h>

// int add_numbers(int a, int b)
// {
//     return a + b;
// }

/**
 * @brief Do not worry about understanding the "int main(...)" line for now. You
 * will learn it in due time, in a different exercise.
 */

int add_numbers(int a, int b); 

int main(int argc, char* argv[])
{
    /* Provide the declaration of function add_numbers above the function main,
     * and move the definition of function add_numbers below the function main.
     */
    int sum = add_numbers(123, 456);
    printf("The sum of 123 and 456 is %d.\n", sum);

    return EXIT_SUCCESS;
}

int add_numbers(int a, int b)
{
     return a + b;
}