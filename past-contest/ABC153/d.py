import math

def attack(x):
    if x == 1:
        return 1
    else:
        return 1 + 2 * attack(math.floor(x / 2))

h = int(input())
print(attack(h))