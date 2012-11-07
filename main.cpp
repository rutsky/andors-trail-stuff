#include <iostream>
#include <sstream>

#include "javarandom.h"

int main( int argc, char const *argv[] )
{
  JavaRandom rnd;

  int64_t start = 0;
  if (argc > 1)
  {
    std::istringstream istr(argv[1]);
    istr >> start;
  }
  int64_t size = 1000 * 60 * 60 * 24;
  if (argc > 2)
  {
    std::istringstream istr(argv[2]);
    istr >> size;
  }

  std::cout << "start: " << start << ", size: " << size << std::endl;
  for (int64_t i = start; 
       //start < 1000 * 60 * 60 * 24 * 365 * 40; 
       i < start + size; 
       ++i)
  {
    if (i % (1000 * 60 * 60 * 10) == 0)
      std::cout << i << std::endl;

    rnd.setSeed(i);
    int nZeroes(0);
    for (int j = 0; j < 3; ++j)
    {
      int32_t const r = rnd.nextInt(int32_t(10000));
      //std::cout << r << " ";
      if (r == 0)
        ++nZeroes;
    }

    if (nZeroes >= 3)
      std::cout << i << ": " << nZeroes << std::endl;
  }
}

// vim: ts=2 sw=2 et:
