// # calculate_multiplication_of_2_matrix
// <Requirement>
// 1. Please provide a C/C++ function that calculates the multiplication of two
// matrices.
// 2. You also need to define your own interface that makes performance better.
#include <iostream>
#include <vector>

#include "helper_function_matrix.h"
#include "multiplication_of_2_matrix.h"

int main() {
  // generate randomly two input matrices by typing size of two input matrices
  int num_row_input_matrix_1, num_col_input_matrix_1;
  int num_row_input_matrix_2, num_col_input_matrix_2;

  std::cout << "num_row_input_matrix_1: ";
  std::cin >> num_row_input_matrix_1;
  std::cout << "num_col_input_matrix_1: ";
  std::cin >> num_col_input_matrix_1;

  std::cout << "num_row_input_matrix_2: ";
  std::cin >> num_row_input_matrix_2;
  std::cout << "num_col_input_matrix_2: ";
  std::cin >> num_col_input_matrix_2;

  std::vector<std::vector<int>> input_matrix_1 = generate_random_integer_matrix(
      num_row_input_matrix_1, num_col_input_matrix_1);
  std::vector<std::vector<int>> input_matrix_2 = generate_random_integer_matrix(
      num_row_input_matrix_2, num_col_input_matrix_2);

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
