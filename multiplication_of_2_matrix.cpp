#include "multiplication_of_2_matrix.h"

#include <iostream>
#include <vector>

std::vector<std::vector<double>> multiply_2_matrix(
    std::vector<std::vector<double>>& matrix_1,
    std::vector<std::vector<double>>& matrix_2) {
  std::vector<std::vector<double>> output_matrix;

  double row_matrix_1 = matrix_1.size();
  if (row_matrix_1 == 0) {
    std::cout << "cannot be multiplied!"
              << "\n"
              << "\n";

    return output_matrix;
  }
  double row_matrix_2 = matrix_2.size();
  if (row_matrix_2 == 0) {
    std::cout << "cannot be multiplied!"
              << "\n"
              << "\n";

    return output_matrix;
  }
  double col_matrix_1 = matrix_1[0].size();
  double col_matrix_2 = matrix_2[0].size();

  // check if this 2 metrix can be multiplied or not
  // if not, then return none
  if (col_matrix_1 != row_matrix_2) {
    std::cout << "cannot be multiplied!"
              << "\n"
              << "\n";

    return output_matrix;
  }

  // resize output matrix
  output_matrix.resize(row_matrix_1);
  for (int i = 0; i < row_matrix_1; ++i) {
    output_matrix[i].resize(col_matrix_2);
  }

  // multiply 2 matrix
  for (int i = 0; i < row_matrix_1; ++i) {
    for (int j = 0; j < col_matrix_2; ++j) {
      for (int k = 0; k < col_matrix_1; ++k) {
        output_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
      }
    }
  }
  return output_matrix;
}