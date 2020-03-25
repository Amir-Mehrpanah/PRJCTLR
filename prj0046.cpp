#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

std::vector<int>
get_primes(int);

int main()
{
  int len = 1000000;
  std::vector<int> primes = get_primes(len + 100);
  int ind = 0;
  int last_ind = 3;
  bool found = false;
  for (size_t x = 9; x < len; x += 2)
  {
    found = false;
    ind = last_ind;
    while (primes[ind] <= x)
    {
      ind++;
    }
    last_ind = --ind;
    for (long i = ind; i >= 0; i--)
    {
      int rem = x - primes[i];
      double t = sqrt(rem / 2);
      if (abs(t - ceil(t)) < .0000005)
      {
        cout << x << " = " << primes[i] << " + 2 x " << t << "^2" << endl;
        found = true;
        break;
      }
    }
    if (!found)
    {
      cout << x << endl;
      return 0;
    }
  }
  return 0;
}

std::vector<int>
get_primes(int max)
{
  std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17};
  int item = 19;
A:
  while (item <= max)
  {
    int sqrtitem = sqrt(item) + 1;
    for (int i : primes)
    {
      if (i > sqrtitem)
        break;
      if (item % i == 0)
      {
        item += 2;
        goto A;
      }
    }
    primes.push_back(item);
    item += 2;
  }
  return primes;
}
