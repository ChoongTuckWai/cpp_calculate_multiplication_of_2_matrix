#include <stdlib.h>

#include <iostream>
#include <vector>

#define MAX_RAMDOM_NUM 10

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