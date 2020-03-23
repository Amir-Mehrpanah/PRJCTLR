#include <iostream>
#include <math.h>

using namespace std;

bool checksum(int i, int j);
bool checksub(int i, int j);
int getsub(int i, int j);

int main()
{
  int i = 2;
  bool i_told_you = false;
  while (!i_told_you)
  {
    for (size_t j = 1; j < i; j++)
    {
      if (i % 1000 == 2)
      {
        cout << i << endl;
      }

      if (checksub(i, j) && checksum(i, j))
      {
        cout <<i<<" , "<<j<<"  --> "<< getsub(i, j) << endl;
        i_told_you = true;
      }
    }
    i++;
  }
}

bool checksum(int i, int j)
{
  double d = (1 + sqrt(36 * (i * i - j * j) - 12 * (i - j) + 1)) / 6;
  if (abs(ceil(d) - d) < 0.00005)
    return true;
  return false;
}

bool checksub(int i, int j)
{
  double d = (1 + sqrt(36 * (i * i + j * j) - 12 * (i + j) + 1)) / 6;
  if (abs(ceil(d) - d) < 0.00005)
    return true;
  return false;
}

int getsub(int i, int j)
{
  return .5 * (3*(i * i - j * j) - (i - j));
}