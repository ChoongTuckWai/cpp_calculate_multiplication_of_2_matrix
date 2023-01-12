// # calculate_multiplication_of_2_matrix
// <Requirement>
// 1. Please provide a C/C++ function that calculates the multiplication of two
// matrices.
// 2. You also need to define your own interface that makes performance better.
#include "multiply_2_matrix.h"

#include <chrono>  //Measure execution time
#include <iostream>
#include <vector>

#include "helper_function_matrix.h"

int main() {
  // generate randomly two input matrices by typing size of two input matrices
  int num_row_input_matrix_1 = 100, num_col_input_matrix_1 = 100;
  int num_row_input_matrix_2 = 100, num_col_input_matrix_2 = 100;

  std::vector<std::vector<double>> input_matrix_1 =
      generate_random_float_matrix(num_row_input_matrix_1,
                                   num_col_input_matrix_1);
  std::vector<std::vector<double>> input_matrix_2 =
      generate_random_float_matrix(num_row_input_matrix_2,
                                   num_col_input_matrix_2);

  // get output matrice and measure execution time
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<std::vector<double>> output_matrix =
      multiply_2_matrix(input_matrix_1, input_matrix_2);
  auto stop = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

  std::cout << "Execution Time:"
            << "\n";
  std::cout << duration.count() << " microseconds"
            << "\n";

  return 0;
}
