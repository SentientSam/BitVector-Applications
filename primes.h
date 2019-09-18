/*
    primes.h
    Samuel Lamb
    cop3330
    1-31-2019
    lamb
*/

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <bitvect.h>



#ifndef _PRIMES_H
#define _PRIMES_H



namespace fsu 
{

size_t PrimeBelow (size_t n, bool ticker = 0);

void AllPrimesBelow (size_t n, std::ostream& os = std::cout, bool ticker = 0);

void Sieve (fsu::BitVector &b, bool ticker = 0);

}

#endif
