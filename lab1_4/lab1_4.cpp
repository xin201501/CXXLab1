#include <iostream>
#include <random>
auto transposeUsingHeapMemory(int matrix[3][3]) {
  int(*result)[3] = new int[3][3];
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      result[j][i] = matrix[i][j];
    }
  }
  return result;
}
int main() {
  int a[3][3];
  bool hasPassedAllTests = true;
  std::uniform_int_distribution<int> u;
  for (size_t count = 1; count <= 100000; count++) {
    std::random_device e;
    for (size_t i = 0; i < 3; i++) {
      for (size_t j = 0; j < 3; j++) {
        a[i][j] = u(e);
      }
    };
    auto b = transposeUsingHeapMemory(a);
    for (size_t i = 0; i < 3; i++) {
      for (size_t j = 0; j < 3; j++) {
        if (a[i][j] != b[j][i]) {
          std::cerr << count << "testcase error! source data:" << a[i][j]
                    << "after transpose:" << b[j][i] << '\n';
          hasPassedAllTests = false;
        }
      }
    }
    delete[] b;
  }
  if (hasPassedAllTests) {
    std::cout << "all tests has passed.";
  }
}