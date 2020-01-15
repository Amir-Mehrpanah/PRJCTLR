/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int
main ()
{
  int n = 1;
  int m = 2;
  int mn = 3;
  int tot = 2;
  int i = 3;
  while (mn < 4000000)
    {
      mn = m + n;
      if (mn % 2 == 0)
	tot += mn;
      cout << i++ << " \tth " << mn << "\tsum " << tot << endl;
      n = m;
      m = mn;
    }

}
