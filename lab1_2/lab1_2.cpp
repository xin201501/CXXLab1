#include <cmath>
#include <iostream>
#include <random>
#include <thread>
using namespace std;
int Maxl(int a, int b) { return a > b ? a : b; }
int Maxl(int a, int b, int c) {
  int partialMax = a > b ? a : b;
  return partialMax > c ? partialMax : c;
}
double Maxl(double a, double b) { return a > b ? a : b; }
double Maxl(double a, double b, double c) {
  double partialMax = a > b ? a : b;
  return partialMax > c ? partialMax : c;
}
int main() {
  bool hasPassedAllTests = true;
  std::thread testThreeIntNumberCase([&hasPassedAllTests] {
    int x, y, z;
    std::string errorMsg;
    uniform_int_distribution<int> u;
    for (size_t count = 1; count <= 100000; count++) {
      random_device e;
      x = u(e);
      y = u(e);
      z = u(e);
      auto max = Maxl(x, y, z), correctAnswer = std::max({x, y, z});
      if (max != correctAnswer) {
        errorMsg += "test case" + std::to_string(count) +
                    "failed,numbers are:" + std::to_string(x) + ' ' +
                    std::to_string(y) + ' ' + std::to_string(z) +
                    ",function result:" + std::to_string(max) +
                    ",correct answer:" + std::to_string(correctAnswer) + '\n';
        cerr << errorMsg;
        errorMsg.clear();
        hasPassedAllTests = false;
      }
    }
  });
  std::thread testTwoIntNumberCase([&hasPassedAllTests] {
    int x, y;
    std::string errorMsg;
    uniform_int_distribution<int> u;
    for (size_t count = 1; count <= 100000; count++) {
      random_device e;
      x = u(e);
      y = u(e);
      auto max = Maxl(x, y), correctAnswer = std::max(x, y);
      if (max != correctAnswer) {
        errorMsg += "test case" + std::to_string(count) +
                    "failed,numbers are:" + std::to_string(x) + ' ' +
                    std::to_string(y) + ' ' +
                    ",function result:" + std::to_string(max) +
                    ",correct answer:" + std::to_string(correctAnswer) + '\n';
        cerr << errorMsg;
        errorMsg.clear();
        hasPassedAllTests = false;
      }
    }
  });
  std::thread testThreeDoubleNumberCase([&hasPassedAllTests]() {
    double x, y, z;
    std::string errorMsg;
    uniform_real_distribution<double> u;
    for (size_t count = 1; count <= 100000; count++) {
      random_device e;
      x = u(e);
      y = u(e);
      z = u(e);
      auto max = Maxl(x, y, z), correctAnswer = std::max({x, y, z});
      if (max != correctAnswer) {
        errorMsg += "test case" + std::to_string(count) +
                    "failed,numbers are:" + std::to_string(x) + ' ' +
                    std::to_string(y) + ' ' + std::to_string(z) +
                    ",function result:" + std::to_string(max) +
                    ",correct answer:" + std::to_string(correctAnswer) + '\n';
        cerr << errorMsg;
        errorMsg.clear();
        hasPassedAllTests = false;
      }
    }
  });
  std::thread testTwoDoubleNumberCase([&hasPassedAllTests]() {
    double x, y;
    std::string errorMsg;
    uniform_real_distribution<double> u;
    for (size_t count = 1; count <= 100000; count++) {
      random_device e;
      x = u(e);
      y = u(e);
      auto max = Maxl(x, y), correctAnswer = std::max(x, y);
      if (max != correctAnswer) {
        errorMsg += "test case" + std::to_string(count) +
                    "failed,numbers are:" + std::to_string(x) + ' ' +
                    std::to_string(y) + ' ' +
                    ",function result:" + std::to_string(max) +
                    ",correct answer:" + std::to_string(correctAnswer) + '\n';
        cerr << errorMsg;
        errorMsg.clear();
        hasPassedAllTests = false;
      }
    }
  });
  testThreeIntNumberCase.join();
  testTwoIntNumberCase.join();
  testThreeDoubleNumberCase.join();
  testTwoDoubleNumberCase.join();
  if (hasPassedAllTests) {
    cout << "all tests have passed.";
  }
  return 0;
}