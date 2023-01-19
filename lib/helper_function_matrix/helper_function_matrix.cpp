#include "helper_function_matrix.h"

#include <stdlib.h>

#include <cmath>
#include <ctime>
#include <iostream>

double** generate_random_float_matrix(int num_row, int num_col) {
  double** new_matrix  = new double*[num_row];;

  for (int i = 0; i < num_row; i++) {
    new_matrix[i] = new double[num_col];
  }

  // set random seed
  srand(static_cast<unsigned>(time(0)));
  // fill matrice
  for (int i = 0; i < num_row; i++) {
    for (int j = 0; j < num_col; j++) {
      new_matrix[i][j] =
          (rand() % MAX_RAMDOM_NUM) +
          ((rand() % MAX_RAMDOM_NUM) / (pow(10, ROUNDING_ATFER_POINT)));
    }
  }

  return new_matrix;
}

void print_matrix(double** target_matrix, int num_row, int num_col) {
  // check if can be print out or not
  if (num_row == 0) {
    std::cout << "empty matrix"
              << "\n";
  } else {
    std::cout << num_row << " " << num_col << "\n";
    for (int i = 0; i < num_row; i++) {
      for (int j = 0; j < num_col; j++) {
        std::cout << target_matrix[i][j] << "\t";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
}