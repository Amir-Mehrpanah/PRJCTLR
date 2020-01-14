/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
int
main ()
{
  int x3s = 1000/3; // 1000 % 3 != 0
  int sumx3s = (x3s*(x3s + 1)/2)*3;
  int x5s = 1000/5 - 1; // 1000 % 5 == 0
  int sumx5s = (x5s*(x5s + 1)/2)*5;
  int x15s = 1000/15;
  int sumx15s = (x15s*(x15s + 1)/2)*15;
  
  int sum = sumx3s + sumx5s - sumx15s;
  
  std::cout<<sum;
  return 0;
}