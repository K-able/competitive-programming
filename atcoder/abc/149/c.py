import math
def prime(n):
    for i in range(2, int(math.sqrt(n))):
        if n % i == 0: return False
    return True

X = int(input())

for i in range(X, 10**8):
    if prime(i):
        print(i)
        exit(0)

print('No prime number in this range')