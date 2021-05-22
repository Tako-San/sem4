#include <fstream>

int main()
{
  std::ofstream ofs{"output", std::ios::app};
  ofs << "first" << std::endl;
  ofs.close();
  return 0;
}
