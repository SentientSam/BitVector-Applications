/*
    primes.cpp
    Samuel Lamb
    cop3330
    1-31-2019
    lamb
*/


#include <cstring>
#include <primes.h>
#include <timer.h>
#include <cmath>
#include <bitvect.h>

namespace fsu
{
size_t PrimeBelow (size_t n, bool ticker)
  // returns largest prime number <= n
  {
    if (n <= 1) return 0;
    if (n == 2) return 2;
    if (n >= n+1)          // is n the largest number test
    {
      std::cerr << " ** PrimeBelow: argument too large for implementation. Execution terminating.\n";
      exit (EXIT_FAILURE);
    }
    fsu::BitVector b(1+n); // a bit n is needed
    Sieve(b, ticker);
    if (n%2 == 0) --n;     // make n odd
    while (n >= 2)          // Ignoring even numbers greater than 2, they are not prime
    {
      if (b[n])
        return n;
      n -= 2;
    }
    return 2;
  } // PrimeBelow()
void AllPrimesBelow (size_t n, std::ostream& os, bool ticker)
  {
    if (n >= n+1)          
    {
      std::cerr << " ** PrimeBelow: argument too large for implementation. Execution terminating.\n";
      exit (EXIT_FAILURE);
    }
    fsu::BitVector b(1+n); 
    Sieve(b, ticker);
    if (n >= 2) os << ' ' << 2;
    size_t i = 3;     
    while (i <= n)          
    {
      if (b[i])
        os << ' ' << i; // outputting number stored in "i"
      i += 2; //increase by 2
    }
    os << std::endl;
  } 
void Sieve (fsu::BitVector& b, bool ticker)
  {
    // set up timer
    fsu::Timer timer;
    fsu::Instant time;
    if (ticker)
    {
      timer.EventReset();
      std::cout << '.' << std::flush; // for p = 2
    }

    // calculate max and square root of max
    const size_t max = b.Size();
    size_t sqrt = 2;
    while (sqrt*sqrt < max)
    {
      ++sqrt;
    }

    // process b                                 
    b.Set();
    b.Unset(0);  // 0 is not prime
    b.Unset(1);  // 1 is not prime

    // clear bits at odd multiples of all odd primes < sqrt(max) - ignore all even bits
    size_t jump;
    for (size_t i = 3; i < sqrt; i += 2)         // ensuring only odd numbers
    {
      if (b[i])  // i is prime
      {
        if (ticker) std::cout << '.' << std::flush;
        jump = 2*i;                              
        for (size_t j = i*i; j < max; j+= jump)  // clear all odd multiples of i above i*i
        {                                        
          b.Unset(j);
        }
      }
    }

    // output elapsed time
    if (ticker)
    {
      time = timer.EventTime();
      std::cout << '\n';
      std::cout << " Sieve time: ";
      time.Write_seconds(std::cout,2);
      std::cout << " sec\n";
    }
  }  // end Sieve()

}
