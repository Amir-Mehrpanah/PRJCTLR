/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

long collatz (long);

int
main ()
{
  long s = 1;
  long ms = 0;
  long len = 0;
  long mlen = 0;
  for (int i = 1000000; i > 2; i--)
    {
      len = 1;
      s = i;
      do
	{
	  s = collatz (s);
	  if (s < 0)
	    {
	      std::cout << "OUT OF RANGE ERROR " << s << std::endl;
	      return 1;
	    }
	  len++;
	}
      while (s != 1);
      if (mlen < len)
	{
	  std::cout << i << " is a better starting point of len " << len <<
	    std::endl;
	  mlen = len;
	  ms = i;
	}
    }
  std::cout << mlen << " start of " << ms << std::endl;
  return 0;
}

long
collatz (long in)
{
  if (in % 2 == 0)
    {
      return in / 2;
    }
  else
    {
      return 3 * in + 1;
    }
}
