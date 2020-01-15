/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

std::vector < int >
get_primes (int);

int
main ()
{
  std::vector < int >primes = get_primes (900000);
for (int i:primes)
    if (600851475143 % i == 0)
      cout << i << endl;

  return 0;
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
