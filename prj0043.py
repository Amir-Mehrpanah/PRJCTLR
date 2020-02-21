def repeat_(a):
    return any((t in a[i+1:]) for i, t in enumerate(a))


def search(index, value, n, cat, cum):
    if index == len(n):
        cum.append(cat)
    else:
        ind = [j for j, t in enumerate(
            n[index]) if t[:2] == value]
        for i in ind:
            if repeat_(cat+n[index][i][-1]):
                continue
            search(index+1, n[index][i][-2:], n, cat+n[index][i][-1], cum)


n = [[f'{j*i:03}' for j in range(0, 500) if len(str(j*i)) <= 3 and not repeat_(f'{j*i:03}')]
     for i in [1, 2, 3, 5, 7, 11, 13, 17]]
t = []
for i in n[0]:
    if repeat_(i):
        continue
    search(1, i[-2:], n, i, t)
print(sum([int(i) for i in t]))
