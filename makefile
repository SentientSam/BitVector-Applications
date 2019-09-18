all: fbitvect.x prime_below.x all_primes_below.x 

prime_below.x: prime_below.o primes.o timer.o bitvect.o
	g++ -std=c++11 -Wall -Wextra -o prime_below.x prime_below.o primes.o timer.o bitvect.o

all_primes_below.x: all_primes_below.o primes.o timer.o bitvect.o
	g++ -std=c++11 -Wall -Wextra -o all_primes_below.x all_primes_below.o primes.o timer.o bitvect.o

fbitvect.x: fbitvect.o bitvect.o
	g++ -std=c++11 -Wall -Wextra -o fbitvect.x fbitvect.o bitvect.o

fbitvect.o: bitvect.cpp
	g++ -std=c++11 -Wall -Wextra -c -I. -I/home/courses/cop3330p/LIB/cpp fbitvect.cpp

prime_below.o: primes.h prime_below.cpp 
	g++ -std=c++11 -Wall -Wextra -c -I. -I/home/courses/cop3330p/LIB/cpp prime_below.cpp

all_primes_below.o: primes.h all_primes_below.cpp
	g++ -std=c++11 -Wall -Wextra -c -I. -I/home/courses/cop3330p/LIB/cpp all_primes_below.cpp 

timer.o:
	g++ -std=c++11 -Wall -Wextra -c -I. -I/home/courses/cop3330p/LIB/cpp  /home/courses/cop3330p/LIB/cpp/timer.cpp

primes.o: primes.h primes.cpp
	g++ -std=c++11 -Wall -Wextra -c -I. -I/home/courses/cop3330p/LIB/cpp primes.cpp

bitvect.o: bitvect.cpp 
	g++ -std=c++11 -Wall -Wextra -c -I. -I/home/courses/cop3330p/LIB/cpp bitvect.cpp
