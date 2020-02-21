file = open('content/d0042.txt', 'r')
names = file.readline().replace('\"', '').split(',')
n = [sum([ord(c)-64 for c in item]) for item in names]
triangles = [1]
for i in range(1, 100):
    triangles.append(triangles[i-1]+i+1)
c = 0
for i in n:
    if i in triangles:
        c += 1
print(c)
