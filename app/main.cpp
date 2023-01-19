// # calculate_multiplication_of_2_matrix
// <Requirement>
// 1. Please provide a C/C++ function that calculates the multiplication of two
// matrices.
// 2. You also need to define your own interface that makes performance better.
#include <lib/helper_function_matrix/helper_function_matrix.h>
#include <lib/multiply_2_matrix/multiply_2_matrix.h>

#include <chrono>  //Measure execution time
#include <iostream>
#include <vector>

#define DEFAULT_MATRIX_SIZE 100

int main(int argc, char *argv[]) {
  // extract size of input matrix
  int num_row_input_matrix_1, num_col_input_matrix_1, num_row_input_matrix_2,
      num_col_input_matrix_2;
  switch (argc) {
    case 1:  // set all two matrix size to default value
      num_row_input_matrix_1 = DEFAULT_MATRIX_SIZE;
      num_col_input_matrix_1 = DEFAULT_MATRIX_SIZE;
      num_row_input_matrix_2 = DEFAULT_MATRIX_SIZE;
      num_col_input_matrix_2 = DEFAULT_MATRIX_SIZE;
    case 2:  // set all two matrix size to argv[1]
      num_row_input_matrix_1 = atoi(argv[1]);
      num_col_input_matrix_1 = atoi(argv[1]);
      num_row_input_matrix_2 = atoi(argv[1]);
      num_col_input_matrix_2 = atoi(argv[1]);
    case 3:  // set first matrix size to argv[1]
             //, then set second matrix size to argv[2]
      num_row_input_matrix_1 = atoi(argv[1]);
      num_col_input_matrix_1 = atoi(argv[1]);
      num_row_input_matrix_2 = atoi(argv[2]);
      num_col_input_matrix_2 = atoi(argv[2]);
    case 5:  // set first matrix size to (argv[1], argv[2])
             //, then set second matrix size to (argv[3], argv[4])
      num_row_input_matrix_1 = atoi(argv[1]);
      num_col_input_matrix_1 = atoi(argv[2]);
      num_row_input_matrix_2 = atoi(argv[3]);
      num_col_input_matrix_2 = atoi(argv[4]);
    default:  // report warning
      std::cout << "Wrong number of arguments, pls follow the instruction."
                << "\n";
      return 0;
  }

  // generate two matrices with random double type value
  std::cout << "num_row_input_matrix_1: " << num_row_input_matrix_1 << "\n";
  std::cout << "num_col_input_matrix_1: " << num_col_input_matrix_1 << "\n";
  std::cout << "num_row_input_matrix_2: " << num_row_input_matrix_2 << "\n";
  std::cout << "num_col_input_matrix_2: " << num_col_input_matrix_2 << "\n";

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
