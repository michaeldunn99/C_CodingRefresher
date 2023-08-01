/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice function declarations and multi-
 * file structure.
 * @details This exercise gets you to decouple function declaration and
 * definition, before moving them in separate files.
 * To see the compilation and execution commands, refer to the first exercise.
 * You are strongly encouraged to type them yourself, rather than copy/pasting,
 * as it may help you memorise.
 **/
#include <stdio.h>
#include <stdlib.h>

int add_numbers_same_file(int a, int b)
{
    return a + b;
}

int add_numbers_different_file(int a, int b)
{
    return a + b;
}

/**
 * @brief Do not worry about understanding the "int main(...)" line for now. You
 * will learn it in due time, in a different exercise.
 */
int main(int argc, char* argv[])
{
    /* Provide the declaration of function add_numbers_same_file above the
     * function main, and the corresponding definition below the function main.
     */
    int sum = add_numbers_same_file(123, 456);
    
    /* Provide the declaration of function add_numbers_different_file in a
     * header file, and move the definition of add_numbers_different_file out of
     * main.c, to your new source file. Then, update the compilation command
     * accordingly and execute the program.
     */
    int sum = add_numbers_different_file(123, 456);

    return EXIT_SUCCESS;
}