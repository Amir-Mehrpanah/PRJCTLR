'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
file = open('content/d0022.txt', 'r') 
names = file.readline().replace('\"','').split(',')
names.sort()
n = sum([sum([ord(c)-64 for c in item])*(ind + 1) for ind,item in enumerate(names)])
print (n)