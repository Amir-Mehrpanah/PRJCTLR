/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

std::vector < int >
factorize (int v, std::vector < int >*primes);
std::vector < int >
get_primes (int);

int
main ()
{
  std::vector < int >primes = get_primes (20);
  int scm_length = primes.size ();
  std::vector < int >scm;
  for (int i = 0; i < scm_length; i++)
    scm.push_back (0);
  for (int i = 2; i < 20; i++)
    {
      std::vector < int >factors = factorize (i, &primes);
      for (int j = 0; j < scm_length; j++)
	if (factors[j] > scm[j])
	  scm[j] = factors[j];
    }
  int multiple = 1;
  for (int i = 0; i < scm_length; i++)
    multiple *= pow (primes[i], scm[i]);
  std::cout << multiple << std::endl;
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
get_primes (int max)
{
  std::vector < int >primes = { 2, 3, 5, 7, 11, 13, 17 };
  int item = 19;
A:while (item <= max)
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
      item += 2;
    }
  return primes;
}
