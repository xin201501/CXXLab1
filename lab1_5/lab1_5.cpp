#include <fstream>
#include <iostream>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int main(int argc, char *argv[]) {
  system("chcp 65001");
  if (argc != 3) {
    cerr << "invalid argument.";
    return -1;
  }
  std::ifstream in(argv[1]);
  if (!in) {
    cerr << argv[1] << "opened failed.";
    return -1;
  }
  std::ofstream out(argv[2]);
  if (!out) {
    cerr << argv[2] << "opened failed";
    return -1;
  }
  std::string lineInfo;
  size_t lineNo = 1;
  while (std::getline(in, lineInfo)) {
    out << lineNo++ << " " << lineInfo << '\n';
  }
  out.close();
  in.close();
  in.open(argv[2]);
  if (!in) {
    cerr << "open output file failed.";
    return -1;
  }
  while (std::getline(in, lineInfo)) {
    cout << lineInfo << '\n';
  }
  return 0;
}