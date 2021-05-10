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

  ac.add_from_file("test/vault")

#ifdef TEST
  ac.add_str("test");
  ac.add_str("rok");
  ac.add_str("roka");
  ac.add_str("strok");
  ac.add_str("t");
#endif

  fs::path pth{argv[1]};
  std::ifstream fst{pth, std::ios::in};

  ac.search(std::istreambuf_iterator<char>(fst), std::istreambuf_iterator<char>());

  return 0;
}