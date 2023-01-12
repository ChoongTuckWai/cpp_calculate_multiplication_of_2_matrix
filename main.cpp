// # calculate_multiplication_of_2_matrix
// <Requirement>
// 1. Please provide a C/C++ function that calculates the multiplication of two
// matrices.
// 2. You also need to define your own interface that makes performance better.

#include <stdlib.h>

#include <cctype>
#include <iostream>
#include <vector>

#define MAX_RAMDOM_NUM 10

// TODO .h

std::vector<std::vector<int>> generate_random_integer_matrix(int num_row,
                                                             int num_col);
void print_matrix(std::vector<std::vector<int>>& target_matrix);
std::vector<std::vector<int>> multiply_2_matrix(
    std::vector<std::vector<int>>& matrix_1,
    std::vector<std::vector<int>>& matrix_2);

int main() {
  // generate randomly two input matrices
  std::vector<std::vector<int>> input_matrix_1 =
      generate_random_integer_matrix(0, 2);
  std::vector<std::vector<int>> input_matrix_2 =
      generate_random_integer_matrix(1, 2);

  // print input matrices
  std::cout << "input_matrix_1:"
            << "\n";
  print_matrix(input_matrix_1);

  std::cout << "input_matrix_2:"
            << "\n";
  print_matrix(input_matrix_2);

  // get output matrice
  std::vector<std::vector<int>> output_matrix =
      multiply_2_matrix(input_matrix_1, input_matrix_2);

  // print output matrice
  std::cout << "output_matrix:"
            << "\n";
  print_matrix(output_matrix);
}

std::vector<std::vector<int>> generate_random_integer_matrix(int num_row,
                                                             int num_col) {
  std::vector<std::vector<int>> new_matrix;

  // resize matrice
  new_matrix.resize(num_row);
  for (int i = 0; i < num_row; ++i) {
    new_matrix[i].resize(num_col);
  }

  // fill matrice
  for (int i = 0; i < num_row; i++) {
    for (int j = 0; j < num_col; j++) {
      new_matrix[i][j] = rand() % MAX_RAMDOM_NUM;
    }
  }

  return new_matrix;
}

void print_matrix(std::vector<std::vector<int>>& target_matrix) {
  int num_row = target_matrix.size();

  // check if can be print out or not
  if (num_row == 0) {
    std::cout << "empty matrix"
              << "\n";
  } else {
    int num_col = target_matrix[0].size();

    for (int i = 0; i < num_row; i++) {
      for (int j = 0; j < num_col; j++) {
        std::cout << target_matrix[i][j] << "\t";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
}

std::vector<std::vector<int>> multiply_2_matrix(
    std::vector<std::vector<int>>& matrix_1,
    std::vector<std::vector<int>>& matrix_2) {
  std::vector<std::vector<int>> output_matrix;

  int row_matrix_1 = matrix_1.size();
  if (row_matrix_1 == 0) {
    std::cout << "cannot be multiplied!"
              << "\n"
              << "\n";

    return output_matrix;
  }
  int row_matrix_2 = matrix_2.size();
  if (row_matrix_2 == 0) {
    std::cout << "cannot be multiplied!"
              << "\n"
              << "\n";

    return output_matrix;
  }
  int col_matrix_1 = matrix_1[0].size();
  int col_matrix_2 = matrix_2[0].size();

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