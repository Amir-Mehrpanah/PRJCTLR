import math
from tqdm import tqdm


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


if __name__ == "__main__":
    p = getprime(979797)
    sum_ = 0
    for i in tqdm(p[4:]):
        s = str(i)
        j = 1
        keep = True
        while j < len(s):
            r = int(s[:-j])
            l = int(s[j:])
            j += 1
            if r not in p or l not in p:
                keep = False
                break
        if keep:
            sum_ += i
    print(sum_)
