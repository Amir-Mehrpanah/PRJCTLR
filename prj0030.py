from tqdm import tqdm

sm = 0

for i in tqdm(range(2,300000)):
    l = str(i)
    k = 0
    for j in l:
        k += int(j)**5
    if k == i:
        print(i)
        sm += i
print(sm)
