#ifndef HELPER_FUNTION_DECLARATIONS_H
    #define HELPER_FUNTION_DECLARATIONS_H
    
    void initialise_adjacency_matrix(int** matrix);

    void print_2D_array(int** matrix);

    void print_ranks(double* ranks);

    int count_links_from_page(int**matrix, int i);

    void normalize_ranks(double* array);

#endif