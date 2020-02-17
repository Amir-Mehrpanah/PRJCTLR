from tqdm import tqdm


def repeat_(a):  # pandigital check
    if any((i == '0') for i in a):
        return True
    return any((t in a[i+1:]) for i, t in enumerate(a))


max_ = 0
for i in tqdm(range(1, 10000000)):
    s = ''
    for j in range(1, 10):
        s += str(i*j)
        if len(s) == 9:
            if not repeat_(s):
                if max_ < int(s):
                    max_ = int(s)
            else:
                break
        elif len(s) > 9:
            break
print(max_)
