/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>

std::vector < int > get_primes(int);

using namespace std;

int
main ()
{
    std::vector < int > primes = get_primes(10001);
    std::cout << primes.back() << std::endl;
    return 0;
}

std::vector < int >
get_primes (int max_ind)
{
    int counter =7;
  std::vector < int >primes = { 2, 3, 5, 7, 11, 13, 17 };
  int item = 19;
A:while (counter<max_ind)
    {
      int sqrtitem = sqrt (item) + 1;
    for (int i:primes)
	{
	  if (i > sqrtitem)
	    break;
	  if (item % i == 0)
	    {
	      item += 2;
	      goto A;
	    }
	}
      primes.push_back (item);
      counter++;
      item += 2;
    }
  return primes;
}