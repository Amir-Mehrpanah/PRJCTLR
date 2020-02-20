from math import sqrt
from tqdm import tqdm


def getprime(m):
    primes = [2, 3, 5, 7, 11, 13, 17, 19]
    last = 23
    with tqdm(total=m) as bar:
        bar.update(19)
        while last < m:
            prime = True
            i = 1
            s = sqrt(last)+1
            while primes[i] < s:
                if last % primes[i] == 0:
                    prime = False
                    break
                i += 1
            if prime:
                primes.append(last)
                bar.update(primes[-1] - primes[-2])
            last += 2
        bar.update(m - primes[-1])
        bar.close()
    return primes


def repeat_(a):
    if any((i == '0') for i in a):
        return True
    return any((t in a[i+1:]) for i, t in enumerate(a))


def pandgital(a):
    a = str(a)
    if repeat_(a):
        return False
    return all((str(i) in a) for i in range(1, len(a)+1))


p = getprime(9876543)
m = max([i for i in p if pandgital(i)])
print(m)
