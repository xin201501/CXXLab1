#include <iostream>
int add(int a, int b);
using namespace std;
int main() {
  int x, y, sum;
  cout << "Enter two numbers:\n";
  cin >> x;
  cin >> y;
  sum = add(x, y);
  cout << "The sum is:" << sum << endl;
  return 0;
}
int add(int a, int b) {
  int c;
  c = a + b;
  return c;
}