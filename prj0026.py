def divide_till_loop(n, d):
    divisions = []
    quotients = []
    while True:
        q = int(n/d)
        r = int(n - q*d)
        quotients.append((n,q,r))
        n = n*10 % 10
        n = r*10 + int(n)
        divisions.append(n)
        for i, item in enumerate(divisions[:-1]):
            if(item == divisions[-1]):
                    return quotients , len(divisions) - i - 1


maxlen = 6
for i in range(2, 1000):
    q , l = divide_till_loop(1, i)
    if(maxlen < l):
        maxlen = l
        print(f"1/{i}\t{l}")#\n{1/i:.57f}\n{q}\n")
print(maxlen)
