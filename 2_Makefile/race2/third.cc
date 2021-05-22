#include <fstream>

int main()
{
  std::ofstream ofs{"output", std::ios::app};
  ofs << "third" << std::endl;
  ofs.close();
  return 0;
}
