
from tqdm import tqdm
import math


def getprime(m):
    primes = [2, 3, 5, 7, 11, 13, 17, 19]
    last = 23
    while last < m:
        prime = True
        i = 1
        s = math.sqrt(last)+1
        while primes[i] < s:
            if last % primes[i] == 0:
                prime = False
                break
            i += 1
        if prime:
            primes.append(last)
        last += 2
    return primes


def circshift(n, i):
    n = str(n)
    for i in range(i):
        n = n[-1]+n[0:-1]
    return int(n)


if __name__ == "__main__":
    count = 0
    primes = getprime(1000000)
    for i in tqdm(primes):
        circprime = True
        for j in range(1, len(str(i))):
            c = circshift(i, j)
            if c not in primes:
                circprime = False
                break
        if circprime:
            count += 1
    print(count)
