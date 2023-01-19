#include "multiply_2_matrix.h"

#include <iostream>

double** multiply_2_matrix(double** matrix_1, double** matrix_2,
                           int num_row_matrix_1, int num_col_matrix_1,
                           int num_row_matrix_2, int num_col_matrix_2) {
  double** output_matrix;

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
  output_matrix = new double*[num_row_matrix_1];
  for (int i = 0; i < num_row_matrix_1; i++) {
    output_matrix[i] = new double[num_col_matrix_2];
  }

  // multiply 2 matrix
  for (int i = 0; i < num_row_matrix_1; ++i) {
    for (int j = 0; j < num_col_matrix_2; ++j) {
      for (int k = 0; k < num_col_matrix_1; ++k) {
        output_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
      }
    }
  }
  return output_matrix;
}