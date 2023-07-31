/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice loops.
 * @details This program contains a loop to built, using both 'while' and 'for'
 * versions.
 * If you end up in a situation where your loop executes indefinitely, issue
 * CTRL + C.
 * (Note: even for Mac users, press CTRL + C, not CMD + C).
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
    // Execute the following statements 10 times, using a 'while' loop.
    printf("[While loop] I should be printed 10 times.\n");

    
    // Execute the following statements 10 times, using a 'for' loop.
    printf("[For loop] I should be printed 10 times.\n");

    return EXIT_SUCCESS;
}