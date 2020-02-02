/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
*******************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

std::vector<int>
get_primes(int max);

int d(int v, std::vector<int> *primes);

int sum_digits(int);

bool sum_of_two_binary_search(int, std::vector<int> *);

std::vector<int>
factorize(int v, std::vector<int> *primes);

std::vector<int>
select(std::vector<int> factors, std::vector<int> *primes);

void vector_print(std::vector<int>);
class BigInt
{
private:
  vector<char> val;

public:
  BigInt(string s)
  {
    int len = s.size();
    for (int i = len - 1; i >= 0 ; i--)
    {
      val.push_back(s[i] - 48);
    }
  }
  BigInt operator+(BigInt v)
  {
    int len = val.size();
    int len2 = v.val.size();
    int maxlen, minlen = 0;
    BigInt temp("");
    BigInt *big;
    if (len > len2)
    {
      minlen = len2;
      maxlen = len;
      big = this;
    }
    else
    {
      minlen = len;
      maxlen = len2;
      big = &v;
    }
    for (int i = 0; i < maxlen; i++)
    {
      if (i < minlen)
        temp.val.push_back(val[i] + v.val[i]);
      else
        temp.val.push_back((*big).val[i]);
    }
    for (int i = maxlen - 1; i >= 0; i--)
    {
      if (temp.val[i] < 9)
      {
        break;
      }
      else if (temp.val[i] > 9)
      {
        temp.val.push_back(0);
        maxlen++;
        break;
      }
    }
    for (int i = 0; i < maxlen - 1; i++)
    {
      temp.val[i + 1] += temp.val[i] / 10;
      temp.val[i] = temp.val[i] % 10;
    }
    return temp;
  }

  BigInt operator++(int)
  {
    int len = val.size();
    for (int i = 0; i < len; i++)
    {
      if (val[i] < 9)
      {
        val[i]++;
        return *this;
      }
      else
      {
        val[i] = 0;
      }
    }
    val.push_back(1);
    return *this;
  }

  void operator=(BigInt v)
  {
    val = v.val;
  }
  void print(void)
  {
    for (int i = val.size() - 1; i >= 0; i--)
    {
      cout << char(val[i] + 48);
    }
    cout << endl;
  }
};

class ComplexCounter
{
private:
  std::vector<int> current;
  std::vector<int> max;
  int len;

public:
  ComplexCounter(std::vector<int> _max)
  {
    len = _max.size();
    for (int i = 0; i < len; i++)
    {
      max.push_back(_max[i]);
      current.push_back(0);
    }
  }

  std::vector<int> peek()
  {
    return current;
  }

  ulong max_selections()
  {
    ulong pmax = 1;
    for (int i = 0; i < len; i++)
    {
      pmax *= max[i] + 1;
    }
    return pmax - 1;
  }

  bool has_next()
  {
    for (int i = 0; i < len; i++)
      if (current[i] < max[i])
        return true;
    return false;
  }
  std::vector<int> pop()
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

int main()
{
  std::vector<int> primes = get_primes(28123);
  std::vector<int> aboundants;
  int len = 28123;
  for (int i = 12; i < len; i++)
  {
    if (i % 2000 == 0)
      std::cout << (float)i / len << std::endl;
    if (d(i, &primes) > i)
      aboundants.push_back(i);
  }
  primes.erase(primes.begin(), primes.end());
  std::cout << "searching ..." << std::endl;
  BigInt sum("0");
  for (int i = 1; i < len; i++)
  {
    if (!sum_of_two_binary_search(i, &aboundants))
    {
      cout << "non " << i << "  ";
      sum.print();

      sum = sum + BigInt(to_string(i));
    }
    if (i % 500 == 0)
    {
      std::cout << "\t%" << (float)i / len << endl;
    }
  }
  sum.print();
}

bool sum_of_two_binary_search(int item, std::vector<int> *x)
{
  int len = (*x).size();
  int searchend = 0;
  for (int i = 0; i < len; i++)
    if ((*x)[i] >= item)
    {
      searchend = i - 1;
      break;
    }
  for (int i = 0; i < searchend; i++)
    for (int j = searchend; j >= i; j--)
      if ((*x)[i] + (*x)[j] == item)
        return true;
  return false;
}

int d(int v, std::vector<int> *primes)
{
  std::vector<int> f = factorize(v, primes);
  f = select(f, primes);
  int len = f.size();
  int sum = 0;
  for (int i = 0; i < len; i++)
  {
    sum += f[i];
  }
  return sum;
}

std::vector<int>
select(std::vector<int> factors, std::vector<int> *primes)
{
  std::vector<int> selections;
  int len = factors.size();
  ComplexCounter counter(factors);
  int max = counter.max_selections();
  std::vector<int> selection = counter.peek();
  int pow_selection = 1;
  for (int i = 0; i < max; i++)
  {
    pow_selection = 1;
    for (int j = 0; j < len; j++)
      pow_selection *= pow((*primes)[j], selection[j]);
    selection = counter.pop();
    selections.push_back(pow_selection);
  }
  return selections;
}

int sum_digits(int v)
{
  int r = v % 10;
  do
  {
    v /= 10;
    r += v % 10;
  } while (v > 0);
  return r;
}

std::vector<int>
factorize(int v, std::vector<int> *primes)
{
  std::vector<int> factors;
  int vcpy = v;
  int primepower = 0;
  for (int i : *primes)
  {
    while (vcpy % i == 0)
    {
      primepower++;
      vcpy /= i;
    }
    factors.push_back(primepower);
    primepower = 0;
    vcpy = v;
  }
  return factors;
}

std::vector<int>
get_primes(int max)
{
  std::vector<int> primes = {2};
  int item = 3;
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

void vector_print(std::vector<int> t)
{
  for (int i = 0; i < t.size(); i++)
  {
    std::cout << t[i] << "  >>>";
    if (cin.get() == 27)
      return;
  }
  std::cout << std::endl;
}
