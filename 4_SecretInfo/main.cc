#include <filesystem>
#include <fstream>
#include <string>

#include "AhoCor.hh"

using std::cin;
using std::cout;
using std::endl;

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    cout << "USAGE: " << argv[0] << " FILENAME" << endl;
    return 1;
  }

  AC::Automaton ac;

  ac.add_from_file("test/vault");

  fs::path pth{argv[1]};
  std::fstream fst{pth};

  std::string str;
  while (fst)
  {
    std::string tmp;
    fst >> tmp;
    str.append(tmp);
  }

  ac.search(str);

  return 0;
}