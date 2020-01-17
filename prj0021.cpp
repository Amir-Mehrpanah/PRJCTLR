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
get_primes (int max);

int d (int v, std::vector < int >*primes);

int sum_digits (int);

std::vector < int >
factorize (int v, std::vector < int >*primes);

std::vector < int >
select (std::vector < int >factors, std::vector < int >*primes);

void vector_print (std::vector < int >);

class ComplexCounter
{
private:
  std::vector < int >current;
    std::vector < int >max;
  int len;
public:
    ComplexCounter (std::vector < int >_max)
  {
    len = _max.size ();
    for (int i = 0; i < len; i++)
      {
	max.push_back (_max[i]);
	current.push_back (0);
      }
  }

  std::vector < int >peek ()
  {
    return current;
  }

  ulong max_selections ()
  {
    ulong pmax = 1;
    for (int i = 0; i < len; i++)
      {
	pmax *= max[i] + 1;
      }
    return pmax - 1;
  }

  bool has_next ()
  {
    for (int i = 0; i < len; i++)
      if (current[i] < max[i])
	return true;
    return false;
  }
  std::vector < int >pop ()
  {
    for (int i = 0; i < len; i++)
      if (current[i] < max[i])
	{
	  current[i]++;
	  return current;
	}
      else
	current[i] = 0;
    return current;
  }
};

int
main ()
{
  std::vector < int >primes = get_primes (10000);
  int sum_divisors;
  int mirror;
  int mirr_counter = 0;
  for (int i = 2; i < 10000; i++)
    {
      sum_divisors = d (i, &primes);
      if (sum_divisors < 10000)
	{
	  mirror = d (sum_divisors, &primes);
	  if (mirror == i && i != sum_divisors)
	    {
	      mirr_counter += i;
	      std::cout << mirr_counter << ": " << i << " " << sum_divisors <<
		std::endl;
	    }
	}
    }
  std::cout << mirr_counter << std::endl;
}

int
d (int v, std::vector < int >*primes)
{
  std::vector < int >f = factorize (v, primes);
  f = select (f, primes);
  int len = f.size ();
  int sum = 0;
  for (int i = 0; i < len; i++)
    {
      sum += f[i];
    }
  return sum;
}

std::vector < int >
select (std::vector < int >factors, std::vector < int >*primes)
{
  std::vector < int >selections;
  int len = factors.size ();
  ComplexCounter counter (factors);
  int max = counter.max_selections ();
  std::vector < int >selection = counter.peek ();
  int pow_selection = 1;
  for (int i = 0; i < max; i++)
    {
      pow_selection = 1;
      for (int j = 0; j < len; j++)
	pow_selection *= pow ((*primes)[j], selection[j]);
      selection = counter.pop ();
      selections.push_back (pow_selection);
    }
  return selections;
}

int
sum_digits (int v)
{
  int r = v % 10;
  do
    {
      v /= 10;
      r += v % 10;
    }
  while (v > 0);
  return r;
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
  std::vector < int >primes = { 2 };
  int item = 3;
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

void
vector_print (std::vector < int >t)
{
  for (int i = 0; i < t.size (); i++)
    std::cout << t[i] << " ";
  std::cout << std::endl;
}
