/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

std::vector < int >
get_primes (int max_ind);
std::vector < int >
factorize (int v, std::vector < int >*primes);

int
main ()
{
  int primes_size = 200;
  std::vector < int >primes = get_primes (primes_size);
  int last = 1;
  int i = 2;
  while (true)
    {
      last += i++;
      int cfactors = 1;
      std::vector < int >factors = factorize (last, &primes);
      for (int j = 0; j < primes_size; j++)
	{
	  cfactors *= factors[j] + 1;
	}
      if (cfactors > 500)
	{
	  std::cout << last << std::endl;
	  break;
	}
    }

  return 0;
}

std::vector < int >
factorize (int v, std::vector < int >*primes)
{
  std::vector < int >factors;
  int vcpy = v;
  int primepower = 0;
for (int i:*primes)
    {
      while (vcpy % i == 0)
	{
	  primepower++;
	  vcpy /= i;
	}
      factors.push_back (primepower);
      primepower = 0;
      vcpy = v;
    }
  return factors;
}

std::vector < int >
get_primes (int max_ind)
{
  int counter = 7;
  std::vector < int >primes = { 2, 3, 5, 7, 11, 13, 17 };
  int item = 19;
A:while (counter < max_ind)
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
