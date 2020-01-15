/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

int reverse (int);

int
main ()
{
  int max, x, y = 0;
  for (int j = 999; j > 100; j--)
    for (int i = 999; i > 100; i--)
      {
	x = j * i;
	y = reverse (x);
	if (y == x && x > max)
	  max = x;
      }
  std::cout << max << std::endl;
  return 0;
}

int
reverse (int v)
{
  int r = v % 10;
  do
    {
      r *= 10;
      v /= 10;
      r += v % 10;
    }
  while (v > 10);
  return r;
}
