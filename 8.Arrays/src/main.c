/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice arrays.
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

int calculate_total_static(int array[10]);
int calculate_total_dynamic(int* array, int size);
int calculate_total_2d_array(int rows, int columns, int array[rows][columns]);

int main(int argc, char* argv[])
{
    // Create an array, statically, of 10 integers.
    int my_array[10];

    /* 
     * Initialise all array elements to their index:
     * Value of first element set to 0.
     * Value of second element set to 1.
     * ...
     * Value of tenth element set to 9.
     */
    for (int i = 0; i < 10; i++)
    {
        my_array[i] = i;
    }


    /* 
     * Calculate the sum of all elements in that array by passing this array to
     * a function that will performan the calculation. Store the result in the
     * variable "total".
     */
    int total = calculate_total_static(my_array);
    printf("Total = %d.\n", total);

    // Allocate an array of integers, dynamically, containing <total> elements.

    int* my_dynamic_array = malloc(sizeof(int) * total);
    if (my_dynamic_array == NULL)
    {
        return 1;
    }
    
    for (int j = 0; j < total; j++)
    {
        my_dynamic_array[j] = j;
    }

    // Repeat the sum calculation you did earlier.
    int dynamic_total = calculate_total_dynamic(my_dynamic_array, total);
    printf("Total = %d.\n", dynamic_total);

    // Free the array you just dynamically allocated.
    free(my_dynamic_array);

    // Allocate a 2D array of 5 x 3 elements.

    int my_2d_array[5][3];
    
    /* Write a function that receives an array of 5 x 3 elements, and returns
     * the sum of all elements.
     */
    for (int k = 0; k < 5; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            my_2d_array[k][l] = 10*k + l;
        }
    }
    int array_sum_2d = calculate_total_2d_array(5, 3, my_2d_array);

    printf("Total is %d.\n", array_sum_2d);
    

    return EXIT_SUCCESS;
}


int calculate_total_static(int array[10])
{
    int running_total = 0;
    for (int i = 0; i < 10; i++)
    {
        running_total += array[i];
    }
    return running_total;
}

int calculate_total_dynamic(int* array, int size)
{
    int running_total = 0;
    for (int i = 0; i < size; i++)
    {
        running_total += array[i];
    }
    return running_total;
}

int calculate_total_2d_array(int rows, int columns, int array[rows][columns])
{
    int running_total = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            running_total += array[i][j];
        }
    }
    return running_total;
}

