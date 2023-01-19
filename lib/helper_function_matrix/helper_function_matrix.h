#ifndef _HELPER_FUNCTION_MATRIX_H_
#define _HELPER_FUNCTION_MATRIX_H_

#include <vector>

#define MAX_RAMDOM_NUM 100
#define ROUNDING_ATFER_POINT 3

std::vector<std::vector<double>> generate_random_float_matrix(int num_row, int num_col);
void print_matrix(std::vector<std::vector<double>>& target_matrix);

#endif
