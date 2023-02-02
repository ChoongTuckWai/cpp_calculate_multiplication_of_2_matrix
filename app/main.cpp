// # calculate_multiplication_of_2_matrix
// <Requirement>
// 1. Please provide a C/C++ function that calculates the multiplication of two
// matrices.
// 2. You also need to define your own interface that makes performance better.
#include <lib/helper_function_matrix/helper_function_matrix.h>
#include <lib/multiply_2_matrix/multiply_2_matrix.h>

#include <chrono>  //Measure execution time
#include <iostream>

#define DEFAULT_MATRIX_SIZE 100

int main(int argc, char* argv[]) {
  // extract size of input matrix
  int num_row_input_matrix_1, num_col_input_matrix_1, num_row_input_matrix_2,
      num_col_input_matrix_2;
  int random_seed;

  if (argc == 2) {  // set all two matrix size to default value
    num_row_input_matrix_1 = DEFAULT_MATRIX_SIZE;
    num_col_input_matrix_1 = DEFAULT_MATRIX_SIZE;
    num_row_input_matrix_2 = DEFAULT_MATRIX_SIZE;
    num_col_input_matrix_2 = DEFAULT_MATRIX_SIZE;
    random_seed = atoi(argv[1]);
  } else if (argc == 3) {  // set all two matrix size to argv[1]
    num_row_input_matrix_1 = atoi(argv[1]);
    num_col_input_matrix_1 = atoi(argv[1]);
    num_row_input_matrix_2 = atoi(argv[1]);
    num_col_input_matrix_2 = atoi(argv[1]);
    random_seed = atoi(argv[2]);
  } else if (argc == 4) {  // set first matrix size to argv[1]
                           //, then set second matrix size to argv[2]
    num_row_input_matrix_1 = atoi(argv[1]);
    num_col_input_matrix_1 = atoi(argv[1]);
    num_row_input_matrix_2 = atoi(argv[2]);
    num_col_input_matrix_2 = atoi(argv[2]);
    random_seed = atoi(argv[3]);
  } else if (argc == 6) {  // set first matrix size to (argv[1], argv[2])
                           //, then set second matrix size to (argv[3], argv[4])
    num_row_input_matrix_1 = atoi(argv[1]);
    num_col_input_matrix_1 = atoi(argv[2]);
    num_row_input_matrix_2 = atoi(argv[3]);
    num_col_input_matrix_2 = atoi(argv[4]);
    random_seed = atoi(argv[5]);
  } else {  // report warning
    std::cout << "Wrong number of arguments, pls follow the instruction."
              << "\n";
    return 0;
  }

  // print num_row and col _input_matrix_1 and 2, random_seed
  std::cout << "num_row_input_matrix_1: " << num_row_input_matrix_1 << "\n";
  std::cout << "num_col_input_matrix_1: " << num_col_input_matrix_1 << "\n";
  std::cout << "num_row_input_matrix_2: " << num_row_input_matrix_2 << "\n";
  std::cout << "num_col_input_matrix_2: " << num_col_input_matrix_2 << "\n";
  std::cout << "random_seed: " << random_seed << "\n";

  // generate two matrices with random float type value
  float* input_matrix_1 = generate_random_float_matrix(
      num_row_input_matrix_1, num_col_input_matrix_1, random_seed);
  float* input_matrix_2 = generate_random_float_matrix(
      num_row_input_matrix_2, num_col_input_matrix_2, random_seed);

  // allocate memory to output matrix
  float* output_matrix =
      allocate_memory_to_matrix(num_row_input_matrix_1, num_col_input_matrix_2);

  // get output matrice and measure execution time
  auto start = std::chrono::high_resolution_clock::now();
  multiply_2_matrix(output_matrix, input_matrix_1, input_matrix_2,
                    num_row_input_matrix_1, num_col_input_matrix_1,
                    num_row_input_matrix_2, num_col_input_matrix_2);
  auto stop = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

  // print Execution Time and First element of matrix
  std::cout << "First three element of matrix: " << output_matrix[0] << " "
            << output_matrix[1] << " " << output_matrix[2] << "\n";
  std::cout
      << "Last three element of matrix: "
      << output_matrix[num_row_input_matrix_1 * num_col_input_matrix_2 - 1]
      << " "
      << output_matrix[num_row_input_matrix_1 * num_col_input_matrix_2 - 2]
      << " "
      << output_matrix[num_row_input_matrix_1 * num_col_input_matrix_2 - 3]
      << "\n";
  std::cout << "Execution Time:\n";
  std::cout << duration.count() << " microseconds\n";

  // deallocate memory of input_matrix_1, input_matrix_2, output_matrix
  deallocate_memory_of_matrix(input_matrix_1);
  deallocate_memory_of_matrix(input_matrix_2);
  deallocate_memory_of_matrix(output_matrix);

  return 0;
}
