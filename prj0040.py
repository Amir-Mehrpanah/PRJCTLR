from numpy import prod
p = ''.join([str(i) for i in range(1,185186)])
j = [10**t-1 for t in range(7)]
print(prod([int(p[t]) for t in j]))