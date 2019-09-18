#include <iostream>
#include <fstream>
#include <primes.h>

int main (int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cout << " ** command line arguments:\n"
              << "    (1) unsigned n  [required]\n"
              << "    (2) bool ticker [optional]\n";
      return EXIT_FAILURE;
  }
  size_t n = atol(argv[1]);
  bool ticker = 0;
  if (argc > 2) ticker = 1;
  fsu::AllPrimesBelow(n, std::cout, ticker);
  return EXIT_SUCCESS;
}
