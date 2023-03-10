#include "multiply_2_matrix.h"

#include <iostream>

bool is_matrix_cannot_be_multipied(int num_row_matrix_1, int num_col_matrix_1,
                                   int num_row_matrix_2, int num_col_matrix_2) {
  // check if matrix is 0 size
  if (num_row_matrix_1 == 0 || num_col_matrix_1 == 0 || num_row_matrix_2 == 0 ||
      num_col_matrix_2 == 0) {
    return true;
  }

  // check if this 2 metrix can be multiplied or not
  // if not, then return none
  if (num_col_matrix_1 != num_row_matrix_2) {
    return true;
  }

  return false;
}

void multiply_2_matrix(float* output_matrix, float* matrix_1, float* matrix_2,
                       int num_row_matrix_1, int num_col_matrix_1,
                       int num_row_matrix_2, int num_col_matrix_2) {
  if (is_matrix_cannot_be_multipied(num_row_matrix_1, num_col_matrix_1,
                                    num_row_matrix_2, num_col_matrix_2)) {
    std::cout << "cannot be multiplied!\n\n";

    return;
  }

  int index_output_row;
  int index_output_col;
  int index_element;
  int pointer_output;
  int pointer_matrix_1_row;
  int pointer_matrix_2_col;

  pointer_output = 0;
  for (index_output_row = 0, pointer_matrix_1_row = 0; index_output_row < num_row_matrix_1;
       index_output_row++, pointer_matrix_1_row += num_col_matrix_1) {
    for (index_output_col = 0; index_output_col < num_col_matrix_2;
         pointer_output += 1, index_output_col++) {
      for (index_element = 0, pointer_matrix_2_col = 0;
           index_element < num_col_matrix_1;
           index_element++, pointer_matrix_2_col += num_col_matrix_2) {
        output_matrix[pointer_output] +=
            matrix_1[pointer_matrix_1_row + index_element] *
            matrix_2[pointer_matrix_2_col + index_output_col];
      }
    }
  }

  return;
}