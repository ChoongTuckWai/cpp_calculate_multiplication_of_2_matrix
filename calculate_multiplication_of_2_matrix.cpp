// # calculate_multiplication_of_2_matrix
// <Requirement>
// 1. Please provide a C/C++ function that calculates the multiplication of two
// matrices.
// 2. You also need to define your own interface that makes performance better.

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

// define function
bool is_num_input_matrix_more_than_one(int argc);
vector<vector<int>> load_matrix(char* file_name);
void print_matrix(vector<vector<int>>& target_matrix);
vector<vector<int>> multiplication_2_matrix(vector<vector<int>>& A,
                                            vector<vector<int>>& B);
void is_this_2_matrix_cannot_be_multiplied(vector<vector<int>>& A,
                                           vector<vector<int>>& B);

int main(int argc, char** argv) {
  if (is_num_input_matrix_more_than_one(argc)) {
    return -1;
  }

  // load matrix
  // TODO: is_file_exist
  // TODO: check type
  // cout << (argc - 1) << " Input Matrix(s):"
  //      << endl;
  // for (int i = 1; i < argc; ++i) {
  //   cout << argv[i] << endl;
  //   // load_matrix(argv[i]);
  //   // ifstream infile("A.txt");
  // }

  // open the file
  // ifstream input_file("A.txt");
  // if (!input_file) {
  //   cerr << "Failed to open File" << endl;
  //   return 1;
  // }

  // istream_iterator<int> start(input_file), end;
  // vector<vector<int>> input_matrix(start, end);
  // cout << "Read " << input_matrix.size() << " numbers" << endl;

  ifstream input_file("A.txt");
  // Read the file line by line
  string line;
  vector<vector<int>> input_matrix;
  vector<int> numbers;
  while (getline(input_file, line)) {
    numbers.push_back(stoi(line));
  }

  // Close the file
  input_file.close();

  // Print the contents of the vector
  for (const auto& l : numbers) {
    cout << l << endl;
  }

  // TODO: check input size

  // multiplication
  // vector<vector<int>> A = {{1, 2}};
  // vector<vector<int>> B = {{2}, {2}};

  // vector<vector<int>> output = multiplication_2_matrix(A, B);

  // // output
  // cout << output.size() << endl;
  // cout << output[0].size() << endl;
  // cout << output[0][0] << endl;

  return 0;
}

bool is_num_input_matrix_more_than_one(int argc) {
  if (argc <= 1) {
    cout << "no any input matrix" << endl;
    return 0;
    // return -1;
  } else if (argc == 2) {
    cout << "only one input matrix" << endl;
    return 1;
  }

  return 0;
}

vector<vector<int>> load_matrix(char* file_name) {
  vector<vector<int>> output_matrix;

  // ifstream inputFile(file_name);
  // istream_iterator<int> start(inputFile), end;
  // vector<vector<int>> input_matrix(start, end);
  // cout << "Read " << input_matrix.size() << " numbers" << endl;

  // cout << "numbers read in:" << endl;
  // copy(input_matrix.begin(), input_matrix.end(),
  //           ostream_iterator<int>(cout, " "));
  // cout << endl;

  // int row_A = input_matrix.size();
  // if (row_A == 0) return output_matrix;
  // int col_A = input_matrix[0].size();
  // if (col_A == 0) return output_matrix;

  // // resize output matrix
  // output_matrix.resize(row_A);
  // for (int i = 0; i < row_A; ++i) {
  //   output_matrix[i].resize(col_A);
  // }

  return output_matrix;
}

vector<vector<int>> multiplication_2_matrix(vector<vector<int>>& matrix_1,
                                            vector<vector<int>>& matrix_2) {
  vector<vector<int>> output_matrix;

  int row_A = matrix_1.size();
  if (row_A == 0) return output_matrix;
  int col_A = matrix_1[0].size();
  if (col_A == 0) return output_matrix;
  int row_B = matrix_2.size();
  if (row_B == 0) return output_matrix;
  int col_B = matrix_2[0].size();
  if (col_B == 0) return output_matrix;

  // resize output matrix
  output_matrix.resize(row_A);
  for (int i = 0; i < row_A; ++i) {
    output_matrix[i].resize(col_B);
  }

  // multiply 2 matrix
  for (int i = 0; i < row_A; ++i) {
    for (int j = 0; j < col_B; ++j) {
      for (int k = 0; k < col_A; ++k) {
        output_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
      }
    }
  }
  return output_matrix;
}