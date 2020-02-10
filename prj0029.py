a=[]
for i in range(2,101):
    for j in range(2,101):
        k = i**j
        if k not in a:
            a.append(k)
print(len(a))