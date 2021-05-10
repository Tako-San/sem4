#include "AhoCor.hh"

int main()
{
  Automaton ac;

  ac.add_str("test");
  ac.add_str("rok");
  ac.add_str("roka");
  ac.add_str("strok");
  ac.add_str("t");

  ac.search("testovaya_stroka!");

  return 0;
}