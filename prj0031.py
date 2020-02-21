import numpy as np
# recursive function turned out to be faster 

def put_item(w, t, i):
    if w[0] not in i:
        i[w[0]] = []
    if(len(w) == 1):
        i[w[0]].append(t / w[0])
        return i
    for l in range(int(t/w[0])+1):
        i[w[0]].append(l)
        put_item(w[1:], t - l*w[0], i)
    return i


def non_recursive_put_item(w, t):
    c = 0
    i = len(w)
    j = {0: list(np.zeros(i-1))}
    while i > 0:
        if i == len(w):
            j[c].append((t - np.dot(j[c], w[:-1]))/w[-1])
            i -= 1
            # yield j[c]
        new_j = j[c][:i]
        new_j[-1] += 1
        if t - np.dot(new_j, w[:i]) >= 0:
            c += 1
            z = len(w) - i - 1
            j[c] = list(np.concatenate([new_j, np.zeros(z)]))
            i = 8
        else:
            i -= 1
    return j


if __name__ == "__main__":
    import time
    t = 200
    w = [200, 100, 50, 20, 10, 5, 2, 1]

    start = time.time()
    i = put_item(w, t, {})  # recursive
    end = time.time()
    print((end - start), len(i[1]))

    # not recursive (can be used with yield)
    start = time.time()
    j = non_recursive_put_item(w, t)
    end = time.time()
    print((end - start), len(j))
