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
  size_t p = fsu::PrimeBelow(n,ticker);
  std::cout << " PrimeBelow (" << n << ") = " << p << '\n';
  return EXIT_SUCCESS;
}
