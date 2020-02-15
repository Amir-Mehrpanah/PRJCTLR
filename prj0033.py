from fractions import Fraction

if __name__ == "__main__":
    for i in range(10, 99):
        for j in range(i+1, 99):
            a = Fraction(i, j)
            n = a.numerator
            d = a.denominator
            c = [t for t in str(i) if t in str(j)]
            if not c or '0' in c:
                continue
            c = c[0]
            nc = str(i).replace(c, '', 1)
            dc = str(j).replace(c, '', 1)
            nc = int(nc)
            dc = int(dc)
            if dc == 0:
                continue
            a = Fraction(nc, dc)
            nc = a.numerator
            dc = a.denominator
            if nc == n and dc == d:
                print(i, j, n, d, nc, dc)
