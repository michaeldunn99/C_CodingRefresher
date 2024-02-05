/**
 * @file main.c
 * @author Ludovic Capelli (l.capelli@epcc.ed.ac.uk)
 * @brief This example is for you to practice everything you have learned by
 * developing a pagerank application. The source code is decorated with comments
 * and documentations at every step.
 * To see the compilation and execution commands, refer to the first exercise.
 * You are strongly encouraged to type them yourself, rather than copy/pasting,
 * as it may help you memorise.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef CONSTANTS_H
    #define CONSTANTS_H

        #define SIZE 5
        #define DUMP_FACTOR 0.85
        #define MAX_ITERATIONS 10 
#endif

#ifndef HELPER_FUNTION_DECLARATIONS_H
    #define HELPER_FUNTION_DECLARATIONS_H
    
    void initialise_adjacency_matrix(int** matrix);

    void print_2D_array(int** matrix);

    void print_ranks(double* ranks);

    int count_links_from_page(int**matrix, int i);

    void normalize_ranks(double* array);

#endif

/**
 * @brief This function contains the architecture of a pagerank application.
 * @details You have to declare and define the variables and functions used
 * throughout this program. Every milestone is indicated with a documentation
 * block, accompanied with a statement "exit(-1)" which aborts the program.
 * This allowed you to progress step by step: removing the "exit(-1)" once you
 * implemented the corresponding block of code.
 */
int main(int argc, char* argv[])
{
    /**
     * @brief Use two defines, "SIZE" = 5 and "DUMP_FACTOR" = 0.85.
     * @details MD Answer - defined in "constants.h" using an inclusion guard
     * 
     * @details SIZE is the number of vertices in the graph (a.k.a: the
     * "graph order"). DUMP_FACTOR is the coefficient controlling the extent to
     * which final ranks are influenced by spreading.
     **/

    /**
     * @brief Create a 2D array of SIZE x SIZE integers, named adjacency_matrix.
     * @details If adjacency_matrix[a][b] = 1, it means that page 'a' has a
     * link to page 'b'. Otherwise, it is 0 and means there is no link from
     * page 'a' to page 'b'.
     * @details MD Answer - adjacency matrix declared below, dynamically
     **/

    // Adjacency matrix - dynamically defined
    
    int** adjacency_matrix = (int **) malloc (SIZE * sizeof(int*));
    //Check to make sure not NULL 
    if (adjacency_matrix == NULL)
    {
        return -1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        adjacency_matrix[i] = (int*) malloc(SIZE * sizeof(int));
        if (adjacency_matrix[i] == NULL)
        {
            return -1;
        }
    }

    /**
     * @brief Declare and define the function initialise_adjacency_matrix.
     * @details It receives a 2D array and initialises such that the upper
     * triangle is made of 1s, the rest of 0s.
     * 
     * Example with SIZE = 5
     * 1 1 1 1 1
     * 0 1 1 1 1
     * 0 0 1 1 1
     * 0 0 0 1 1
     * 0 0 0 0 1
     * 
     * 
     * @details - MD Answer: intialized in function within helper_functions.c
     **/

    initialise_adjacency_matrix(adjacency_matrix);

    /**
     * @brief Declare and define the function print_2D_array.
     * @details This function receives a 2D array of SIZE x SIZE elements, and
     * prints it as follows:
     * 
     *                 The right-most
     *                 dimension my_arr[...][X]
     *                 +------------------>
     * The leftmost    | [0][0]  [0][1]  
     * dimension       | [1][0]  [1][1]
     * my_arr[X][...]  | [2][0]  [2][1]
     *  
     * @details -  MD Answer: Function described below main function
     *          
     **/
    print_2D_array(adjacency_matrix);

    /**
     * @brief Create two 1D arrays of SIZE doubles, named "ranks" and
     * "prev_ranks".
     * @details The array "ranks" will contain the final rank of each page,
     * whereas "prev_ranks" will hold ranks from previous iterations that are
     * needed in calculations.
     * 
     * @details - MD Answer: "ranks" and "prev_ranks" defined below
     **/
    size_t size_of_ranks = SIZE;

    double* ranks = (double*) malloc(sizeof(double) * size_of_ranks);
    if (ranks == NULL)
    {
        return -1;
    }
    

    double* prev_ranks = (double*) malloc(sizeof(double) * size_of_ranks);
    if (prev_ranks == NULL)
    {
        return -1;
    }

    /**
     * @brief Initialise array of ranks to 1 / SIZE.
     * @details By default, 1 / SIZE is seen as a division of integers and will
     * result in 0. To make sure that the terms are treated as doubles, we will
     * cast them as follows: 1.0 / (double)SIZE.
     * 
     * @details MD Answer - Ranks initialised below as required.
     **/

    for (int j = 0; j < SIZE; j++)
    {
        ranks[j] = 1.0 / (double) SIZE;
    }

    /**
     * @brief Declare and define a function that prints an array of SIZE
     * elements, and call it to print the values of the rank array.
     * 
     * @details - MD Answer: 
     *          - Function defined below main function 
     *          
     **/
    printf("Initial ranks:\n");
    print_ranks(ranks);

    /**
     * @brief Create a loop for <MAX_ITERATION> iterations.
     **/

    //////////////////////
    // BEGIN: MAIN LOOP //
    //////////////////////
    for (int k = 0; k < MAX_ITERATIONS; k++)
    {
        /**
        * @brief Copy the values from array <ranks> to array <prev_ranks>.
        **/
       for (int a = 0; a < SIZE; a++)
       {
            prev_ranks[a] = ranks[a];
       }
        
        /**
        * @brief Reset the values of array <ranks> to 0.
        **/
        for (int m = 0; m < SIZE; m++)
        {
            ranks[m] = 0;
        }
        
        /**
         * @brief Create a loop of <SIZE> iterations.
         * @details We will assume that your iterator is named "i", it will
         * represent the source webpage.
         **/

        //////////////////////
        // BEGIN: LOOP I    //
        //////////////////////
        
        for (int i = 0; i < SIZE; i++)
        {
            /**
             * @brief Create a loop of <SIZE> iterations.
             * @details We will assume that your iterator is named "j", it will
             * represent the target webpage.
             **/
        
            //////////////////////
            // BEGIN: LOOP J    //
            //////////////////////

            for (int j = 0; j < SIZE; j++)
            {
                
                /**
                * @brief If the webpage "i" has no link to webpage "j", skip
                * this iteration.
                **/
                if (adjacency_matrix[i][j] == 0)
                {
                    continue;
                }


                /**
                 * @brief Declare and define function count_links_from_page.
                 * @details This function counts the number of links that a
                 * given page has with all other webpages. It receives the 
                 * connectivity matrix, and the source webpage considered. It
                 * returns the number of links obtained.
                 */

                int link_count = count_links_from_page(adjacency_matrix, i);

                /**
                 * @brief If the number of links is strictly greater than 0,
                 * add (1 / link_count)th of the source webpage's previous rank
                 * to the current rank of the target webpage.
                 */

                if (link_count > 0)
                {
                    ranks[j] += (1.0 / ((double) link_count)) * prev_ranks[i];
                }
                
            //////////////////////
            // END: LOOP J      //
            //////////////////////    
            }

        //////////////////////
        // END: LOOP I      //
        //////////////////////
        }

    /**
     * @brief Declare and define the function normalise_ranks.
     * @details This function receives a 1D array of SIZE elements, and 
     * updates the value of every element to:
     * new_value = current_value x DUMP_FACTOR + (1.0 - DUMP_FACTOR) / SIZE.         * 
     * 
     * @details - MD Answer:
    *           - Function defined below main function
     **/

    normalize_ranks(ranks);

    /**
     * @brief Calculate the sum of all ranks and prints the value obtained.
     **/

    double rank_sum = 0.00;
    for (int n = 0; n < SIZE; n++)
    {
        rank_sum += ranks[n];
    }
    printf("Rank_sum: %.2f\n", rank_sum); 

    
    /**
     * @brief Print all ranks.
     **/

    printf("Iteration %d - updated ranks:\n", k);
    print_ranks(ranks);

    //////////////////////
    // END: MAIN LOOP   //
    //////////////////////

    }
    for (int q = 0; q < SIZE; q++)
    {
        free(adjacency_matrix[q]);
    }
    free(adjacency_matrix);
    free(ranks);
    free(prev_ranks);


    return EXIT_SUCCESS;
}


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
    printf("\n");
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
    for (int i = 0; i < SIZE; i++)
    {
        printf("%.2f ", array[i]);
    }
    printf("\n\n");
}


/// @brief counts the number of links that a given page has with all other webpages. 
/// @param matrix - pointer to a 2d array of integers (in this case the adjacency matrix)
/// @param i (Row in question (in this case the number of the webpage considered))
/// @return Returns total number of links from webpage i to every other webpage

int count_links_from_page(int** matrix, int i)
{
    int page_count = 0;
    for (int j = 0; j < SIZE; j++)
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

