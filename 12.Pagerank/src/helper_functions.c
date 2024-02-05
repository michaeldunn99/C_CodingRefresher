#include <stdio.h>
#include "constants.h"
#include "helper_function_declarations.h"

/** 
 * @brief Function that initializes a matrix to upper-triangular form
 * @details This function accepts as parameter an int ** pointer to a matrix of size SIZE*SIZE and
 * and sets the upper triangular values to 1 and the strict lower triangular values
 * to 0. 
 * @param matrix - pointer to a matrix assumed to be of size SIZE x SIZE
 * 
 */ 
void initialise_adjacency_matrix(int** matrix)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i > j)
            {
                matrix[i][j] = 0;
            }
            else
            {
                matrix[i][j] = 1;
            }
        }
    }
}

/** 
 * @brief Function prints each entry the matrix
 * @details This function accepts as parameter an int ** pointer to a matrix of size SIZE*SIZE and
 * and prints each entry, taking a new line for each new row of the matrix. 
 * @param matrix - Pointer to a matrix assumed to be of size SIZE x SIZE
 * 
 */
void print_2D_array(int ** matrix)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/** 
 * @brief Function prints each entry of an array of doubles
 * @details This function accepts as parameter an double * pointer to an array of size SIZE and
 * and prints each entry to one line.
 * @param array - Pointer to an array of type double, assumed to be of size SIZE
 * 
 */
void print_ranks(double* array)
{
    printf("\nRanks:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}


/// @brief counts the number of links that a given page has with all other webpages. 
/// @param matrix - pointer to a 2d array of integers (in this case the adjacency matrix)
/// @param i (Row in question (in this case the number of the webpage considered))
/// @return Returns total number of links from webpage i to every other webpage

int count_links_from_page(int** matrix, int i)
{
    int page_count = 0;
    for (int j = 0; j < SIZE; i++)
    {
        if (matrix[i][j] == 1)
        {
            page_count++;
        }
    }
    return page_count;
}


/**
 * @brief Normalize the ranks in the given array.
 *
 * This function takes an array of ranks and normalizes them by
 * applying formula: new_value = current_value x DUMP_FACTOR + (1.0 - DUMP_FACTOR) / SIZE. 
 *
 * @param array The array of ranks to be normalized, assumed to be of size SIZE.
 */

void normalize_ranks(double* array)
{
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = DUMP_FACTOR * array[i] + (1.0 - DUMP_FACTOR) / ((double) SIZE);
    }
}

