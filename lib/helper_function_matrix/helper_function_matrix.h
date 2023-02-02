#ifndef _HELPER_FUNCTION_MATRIX_H_
#define _HELPER_FUNCTION_MATRIX_H_

#define MAX_RAMDOM_NUM 100
#define ROUNDING_ATFER_POINT 3

#define USE_TIME_AS_RANDOM_SEED -1

double** generate_random_float_matrix(
    int num_row, int num_col, int random_seed = USE_TIME_AS_RANDOM_SEED);

void print_matrix(double** target_matrix, int num_row, int num_col);

void delete_matrix(double** target_matrix, int num_row);

#endif
