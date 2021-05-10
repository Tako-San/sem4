#include "frac.hh"

using namespace my_math;

int main( )
{
  Frac f1{-1, -2};

  std::cout << "Frac f1{-1, -2}: " << f1 << std::endl;

  std::cout << "f1 + 3 = " << f1 + 3 << std::endl;
  std::cout << "3 + f1 = " << 3 + f1 << std::endl;

  std::cout << "f1 - 3 = " << f1 - 3 << std::endl;
  std::cout << "3 - f1 = " << 3 - f1 << std::endl;

  std::cout << "f1 * 3 = " << f1 * 3 << std::endl;
  std::cout << "3 * f1 = " << 3 * f1 << std::endl;

  std::cout << "f1 / 3 = " << f1 / 3 << std::endl;
  std::cout << "3 / f1 = " << 3 / f1 << std::endl;

  std::cout << (Frac{6, 2} == 3) << std::endl;
  std::cout << Frac{51, 17} << std::endl;

  return 0;
}
