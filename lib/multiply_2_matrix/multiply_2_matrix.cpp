#include "multiply_2_matrix.h"

#include <iostream>

void multiply_2_matrix(float* output_matrix, float* matrix_1, float* matrix_2,
                       int num_row_matrix_1, int num_col_matrix_1,
                       int num_row_matrix_2, int num_col_matrix_2) {
  if (num_row_matrix_1 == 0) {
    std::cout << "cannot be multiplied!\n\n";

    return;
  }
  if (num_row_matrix_2 == 0) {
    std::cout << "cannot be multiplied!\n\n";

    return;
  }

  // check if this 2 metrix can be multiplied or not
  // if not, then return none
  if (num_col_matrix_1 != num_row_matrix_2) {
    std::cout << "cannot be multiplied!\n\n";

    return;
  }

  int pointer_output_row;
  int pointer_output, pointer_matrix_1, pointer_matrix_2;
  for (int row = 0; row < num_row_matrix_1; ++row) {
    pointer_output_row = row * num_col_matrix_2;
    pointer_matrix_1 = row * num_col_matrix_1;
    for (int pointer = 0; pointer < num_col_matrix_1; ++pointer) {
      pointer_matrix_2 = pointer * num_col_matrix_2;
      for (int col = 0; col < num_col_matrix_2; ++col) {
        pointer_output = pointer_output_row + col;
        output_matrix[pointer_output] += matrix_1[pointer_matrix_1 + pointer] *
                                         matrix_2[pointer_matrix_2 + col];
      }
    }
  }
  return;
}