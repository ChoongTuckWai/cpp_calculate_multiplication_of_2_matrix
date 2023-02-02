#include "helper_function_matrix.h"

#include <stdlib.h>

#include <cmath>
#include <ctime>
#include <iostream>

float* generate_random_float_matrix(int num_row, int num_col,
                                     int random_seed) {
  // allocate memory
  float* new_matrix = allocate_memory_to_matrix(num_row, num_col);

  // set random seed
  if (random_seed == USE_TIME_AS_RANDOM_SEED) {
    srand(static_cast<unsigned>(time(0)));
  } else {
    srand(static_cast<unsigned>(random_seed));
  }

  // fill matrice
  for (int i = 0; i < num_row; i++) {
    for (int j = 0; j < num_col; j++) {
      new_matrix[i * num_row + j] =
          (rand() % MAX_RAMDOM_NUM) +
          ((rand() % MAX_RAMDOM_NUM) / (pow(10, ROUNDING_ATFER_POINT)));
    }
  }

  return new_matrix;
}

float* allocate_memory_to_matrix(int num_row, int num_col) {
  // allocate memory
  float* new_matrix = new float[num_row * num_col];

  return new_matrix;
}

void deallocate_memory_of_matrix(float* target_matrix) {
  delete[] target_matrix;
}

void print_matrix(float* target_matrix, int num_row, int num_col) {
  // check if can be print out or not
  if (num_row == 0) {
    std::cout << "empty matrix"
              << "\n";
  } else {
    std::cout << num_row << " " << num_col << "\n";
    for (int i = 0; i < num_row; i++) {
      for (int j = 0; j < num_col; j++) {
        std::cout << target_matrix[i*num_row + j] << "\t";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
}