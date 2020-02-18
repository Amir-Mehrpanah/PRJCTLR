from math import sqrt
from tqdm import tqdm

p = 0
cmax = 0
for i in tqdm(range(12, 1001)):
    c = 0
    for j in range(1, int(i/(3.4))+1):
        # i / 3 > j isosceles's j<=i/(2+sqrt(2)) -> 2 + 1.41 = 3.41
        for k in range(int(i/2)-j+1, int(i/2-j/2+1)+1):
            # j <= k <= z , z = i -j -k , min -> i/2 -j < +k , max -> k <= i/2 -x/2
            z = sqrt(j**2+k**2)
            t = i - j - k
            if z - t == 0:
                c += 1
    if cmax < c:
        cmax = c
        p = i
print(cmax, p)
