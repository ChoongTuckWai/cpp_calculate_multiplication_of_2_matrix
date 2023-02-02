#include "multiply_2_matrix.h"

#include <iostream>

#define BLOCK_SIZE 100

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

  // multiply 2 matrix
  // for (int row = 0; row < num_row_matrix_1; row += BLOCK_SIZE) {
  //   for (int col = 0; col < num_col_matrix_2; col += BLOCK_SIZE) {
  //     for (int pointer = 0; pointer < num_col_matrix_1; pointer +=
  //     BLOCK_SIZE) {
  //       for (int block_row = row; block_row < row + BLOCK_SIZE; ++row) {
  //         for (int block_col = col; block_col < col + BLOCK_SIZE; ++col) {
  //           for (int block_pointer = pointer;
  //                block_pointer < pointer + BLOCK_SIZE; ++pointer) {
  //             output_matrix[(block_row * num_col_matrix_2) + block_col] +=
  //                 matrix_1[(block_row * num_col_matrix_1) + block_pointer] *
  //                 matrix_2[(block_pointer * num_col_matrix_2) + block_col];
  //           }
  //         }
  //       }
  //     }
  //   }
  // }
  int pointer_output_row;
  int pointer_output, pointer_matrix_1;
  for (int row = 0; row < num_row_matrix_1; ++row) {
    pointer_output_row = row * num_col_matrix_2;
    pointer_matrix_1 = row * num_col_matrix_1;
    for (int col = 0; col < num_col_matrix_2; ++col) {
      pointer_output = pointer_output_row + col;
      for (int pointer = 0; pointer < num_col_matrix_1; ++pointer) {
        output_matrix[pointer_output] +=
            matrix_1[pointer_matrix_1 + pointer] *
            matrix_2[pointer * num_col_matrix_2 + col];
      }
    }
  }
  return;
}