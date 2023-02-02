#include "multiply_2_matrix.h"

#include <iostream>

#define BLOCK_SIZE 128

float** multiply_2_matrix(float** matrix_1, float** matrix_2,
                           int num_row_matrix_1, int num_col_matrix_1,
                           int num_row_matrix_2, int num_col_matrix_2) {
  float** output_matrix;

  if (num_row_matrix_1 == 0) {
    std::cout << "cannot be multiplied!"
              << "\n"
              << "\n";

    return output_matrix;
  }
  if (num_row_matrix_2 == 0) {
    std::cout << "cannot be multiplied!"
              << "\n"
              << "\n";

    return output_matrix;
  }

  // check if this 2 metrix can be multiplied or not
  // if not, then return none
  if (num_col_matrix_1 != num_row_matrix_2) {
    std::cout << "cannot be multiplied!"
              << "\n"
              << "\n";

    return output_matrix;
  }

  // resize output matrix
  output_matrix = new float*[num_row_matrix_1];
  for (int i = 0; i < num_row_matrix_1; i++) {
    output_matrix[i] = new float[num_col_matrix_2];
  }

  // multiply 2 matrix
  // for (int k = 0; k < num_col_matrix_1; k += BLOCK_SIZE) {
  //   for (int j = 0; j < num_col_matrix_2; j += BLOCK_SIZE) {
  //     for (int i = 0; i < num_row_matrix_1; i += BLOCK_SIZE) {
  //       for (int block_k = k; block_k < k + BLOCK_SIZE; ++k) {
  //         for (int block_j = j; block_j < j + BLOCK_SIZE; ++j) {
  //           for (int block_i = i; block_i < i + BLOCK_SIZE; ++i) {
  //             output_matrix[block_i][block_j] += matrix_1[block_i][block_k] *
  //             matrix_2[block_k][block_j];
  //           }

  //         }
  //       }
  //     }
  //   }
  // }

  for (int k = 0; k < num_col_matrix_1; ++k) {
    for (int i = 0; i < num_row_matrix_1; ++i) {
      for (int j = 0; j < num_col_matrix_2; ++j) {
        output_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
      }
    }
  }
  return output_matrix;
}