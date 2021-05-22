#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

int main()
{
  fs::path created_path{"."};
  created_path /= "sum.cc";

  std::filesystem::create_directories(created_path.parent_path());

  std::string prgrm{R"(
  int sum(int lhs, int rhs)
  {
    return lhs + rhs;
  }
  )"};

  std::ofstream ofs(created_path);
  ofs << prgrm << std::endl; 
  ofs.close();

  return 0;
}