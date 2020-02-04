'''

                            Online Python Compiler.
                Code, Compile, Run and Debug python program online.
Write your code in this editor and press "Run" button to execute it.

'''
import math


def nth_permutation(num, ind):
    factors = []
    [factors.append(math.factorial(i)) for i in range(1, num)]
    numbers = list(range(num))
    placed = []
    index = 0
    while len(numbers) >= 2:
        if(index*factors[len(numbers) - 2] < ind):
            index += 1
        else:
            ind -= (index - 1) * factors[len(numbers) - 2]
            placed.append(numbers[index - 1])
            del numbers[index - 1]
            index = 0
    placed.append(numbers[0])
    print(placed)


if __name__ == "__main__":
    n = 10  # input('input permutation length')
    nth = 1000000  # input('input index')
    nth_permutation(n, nth)
