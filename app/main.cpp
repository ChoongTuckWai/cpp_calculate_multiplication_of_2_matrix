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

  if (argc == 1) {                                 // hello world
    float input_matrix_1[6] = {1, 2, 3, 4, 5, 6};  // 2x3
    float input_matrix_2[12] = {1, 3, 5, 7, 2, 4, 6, 8, 12, 14, 16, 18};  // 3x4
    float gt[8] = {41, 53, 65, 77, 86, 116, 146, 176};                    // 2x4
    float output_matrix[8] = {0};
    std::cout << "Hello World for this app\n";

    multiply_2_matrix(output_matrix, input_matrix_1, input_matrix_2, 2, 3, 3,
                      4);
    std::cout << "GT  = ";
    print_matrix(gt, 1, 8);
    std::cout << "ret  = ";
    print_matrix(output_matrix, 1, 8);

    return 0;
  }

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
    std::cout << "Wrong number of arguments, pls follow the instruction.\n"
              << "[USAGE] for hello world:\n./app\n"
              << "[USAGE] for both matrix in same size:\n./app [size] [random_seed]\n"
              << "[USAGE] for 2 matrix in diffrence size:\n./app [m1_size] [m2_size] [random_seed]\n"
              << "[USAGE] for 2 matrix in diffrence row and col:\n./app  [m1_row] [m1_col] [m2_row] [m2_col] [random_seed]\n";
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
  std::cout << duration.count() / 1000000.0 << " seconds\n";

  // deallocate memory of input_matrix_1, input_matrix_2, output_matrix
  deallocate_memory_of_matrix(input_matrix_1);
  deallocate_memory_of_matrix(input_matrix_2);
  deallocate_memory_of_matrix(output_matrix);

  return 0;
}
