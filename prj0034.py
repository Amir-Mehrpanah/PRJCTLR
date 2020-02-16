
from tqdm import tqdm
import math
if __name__ == "__main__":
    sum_ = 0
    for i in tqdm(range(3, 1000000)):
        s = 0
        for d in str(i):
            s += math.factorial(int(d))
        if s == i:
            sum_ += i
    print(sum_)