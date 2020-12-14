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
  std::ifstream in(argv[1], std::ios::binary);
  if (!in) {
    cerr << argv[1] << "opened failed.";
    return -1;
  }
  std::ofstream out(argv[2], std::ios::binary);
  if (!out) {
    cerr << argv[2] << "opened failed";
    return -1;
  }
  long long offset = 0, lineNo = 1;
  std::string lineInfo;
  char delim = '\n';
  while (in) {
    while (in.peek() != '\n') {
      offset++;
    }
    lineInfo.resize(offset);
    in.seekg(-offset, std::ios_base::cur);
    in.read(lineInfo.data(), offset + 1);
    lineInfo.insert(0, std::to_string(lineNo));
    lineNo++;
    out.write(lineInfo.data(), lineInfo.size());
    out.write(&delim, 1);
  }
  out.close();
  in.open(argv[2], std::ios::binary);
  if (!in) {
    cerr << "open output file failed.";
    return -1;
  }
  offset = 0;
  while (in.ignore()) {
    offset++;
  }
  in.seekg(0, std::ios_base::beg);
  lineInfo.resize(offset);
  in.read(lineInfo.data(), offset);
  cout << lineInfo;
  return 0;
}