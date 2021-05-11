#include <filesystem>
#include <fstream>
#include <string>

#include "AhoCor.hh"

namespace fs = std::filesystem;
namespace AC = AhoCorasick;

int print_msg(const char *str)
{
  std::cout << "Path '" << str << "' doesn't exist." << std::endl;
  return 1;
}

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    std::cout << "USAGE: " << argv[0] << " VAUILT_DIR FILENAME" << std::endl;
    return 1;
  }

  for (int i = 1; i < 3; ++i)
    if (!fs::exists(argv[i]))
      return print_msg(argv[i]);

  AC::Automaton ac;
  ac.add_from_file(argv[1]);

  std::ifstream fst{argv[2], std::ios::in};
  ac.search(std::istreambuf_iterator<char>(fst), std::istreambuf_iterator<char>());

  return 0;
}
