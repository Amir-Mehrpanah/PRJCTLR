from tqdm import tqdm

def palindromic(s):
    if type(s) == int:
        s = str(s)
    l = len(s)-1
    return all((t == s[l-i]) for i, t in enumerate(s))


def binarize(n):
    result = []
    while n > 0:
        result.append(n % 2)
        n = int(n/2)
    return result


if __name__ == "__main__":
    sum_ = 0
    for i in tqdm(range(1000000)):
        if palindromic(i):
            b = binarize(i)
            if palindromic(b):
                sum_ += i
    print(sum_)