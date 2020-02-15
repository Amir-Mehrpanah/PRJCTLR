from tqdm import tqdm


def repeat(a, b) -> bool:
    if any((t in str(b)) for t in str(a)):
        return True
    return False


def repeat_(a):
    a = str(a)
    if any((i == '0') for i in a):
        return True
    return any((t in a[i+1:]) for i, t in enumerate(a))


def pandigital(a, b, c) -> bool:
    if repeat(a, c):
        return False
    if repeat(b, c):
        return False
    return len(str(a)+str(b)+str(c)) == 9


if __name__ == "__main__":
    c = []
    sum_ = 0
    for i in tqdm(range(2, 200)):
        for j in range(i + 1, 2000):
            if repeat_(i):
                continue
            if repeat_(j):
                continue
            if not repeat(i, j):
                u = i*j
                if repeat_(u):
                    continue
                if u not in c and pandigital(i, j, u):
                    c.append(u)
                    sum_ += u
                    print(i, j, u)
    print(sum_)
