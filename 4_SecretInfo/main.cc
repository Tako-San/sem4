#include <filesystem>
#include <fstream>
#include <string>

#include "AhoCor.hh"

namespace fs = std::filesystem;

int main(int argc, char ** argv)
{
  if (argc < 2)
  {
    cout << "USAGE: " << argv[0] << " FILENAME" << endl;
    return 1;
  }

  Automaton ac;

  for (auto & file : fs::directory_iterator("test/vault"))
  {
    std::ifstream fst{file.path()};
    std::string str;

    while(fst)
    {
      std::string tmp;
      fst >> tmp;
      str.append(tmp);
    }

    fst.close();
    ac.add_str(str);
  }

  fs::path pth{argv[1]};
  std::fstream fst{pth};

  std::string str;
  while(fst)
  {
    std::string tmp;
    fst >> tmp;
    str.append(tmp);
  }

  ac.search(str);

  return 0;
}