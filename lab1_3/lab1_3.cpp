#include <ctime>
#include <iostream>
#include <random>
void transpose(int matrix[3][3], int result[3][3]) {
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      result[j][i] = matrix[i][j];
    }
  }
}
int main() {
  int a[3][3];
  bool hasPassedAllTests = true;
  std::uniform_int_distribution<int> u;
  for (size_t count = 1; count <= 100000; count++) {
    std::random_device e;
    for (auto &i : a) {
      for (int &j : i) {
        j = u(e);
      }
    }
    int b[3][3];
    transpose(a, b);
    for (size_t i = 0; i < 3; i++) {
      for (size_t j = 0; j < 3; j++) {
        if (a[i][j] != b[j][i]) {
          std::cerr << count << "testcase error! source data:" << a[i][j]
                    << "after transpose:" << b[j][i] << '\n';
          hasPassedAllTests = false;
        }
      }
    }
  }
  if (hasPassedAllTests) {
    std::cout << "all tests have passed.";
  }
}