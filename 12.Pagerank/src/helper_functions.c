#include <stdio.h>
#include "constants.h"
#include "helper_function_declarations.h"

/** 
 * @brief Function that initializes the adjacency matrix
 * @details This function accepts as parameter an int ** pointer to a matrix of size SIZE*SIZE and
 * and sets the upper triangular values to 1 and the strict lower triangular values
 * to 0. 
 * @param matrix - pointer to a matrix assumed to be of size SIZE x SIZE
  * */ 
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

