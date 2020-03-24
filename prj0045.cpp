#include <iostream>
#include <math.h>

using namespace std;

bool check_tri_hex(unsigned long long n);
unsigned long long get_tri(unsigned long long n);

int main()
{
  unsigned long long i = 1;
  int x = 0;
  while (x < 15)
  {
    if (check_tri_hex(i))
    {
      x++;
      cout << i << "  --> " << get_tri(i) << " :\t" << x << endl;
    }
    i++;
  }
}

bool check_tri_hex(unsigned long long n)
{
  double d = sqrt(1 + 4 * n * (3 * n - 1));
  double tp = (d + 1) / 4;
  double th = (d - 1) / 2;
  if (abs(ceil(tp) - tp) < 0.000000005 && abs(ceil(th) - th) < 0.000000005)
  {
    cout << tp << " , " << th << " , ";
    return true;
  }
  return false;
}

unsigned long long get_tri(unsigned long long n)
{
  return n * (3 * n - 1) / 2;
}