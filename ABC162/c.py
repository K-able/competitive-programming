import math
from functools import reduce

def gcd(*numbers):
    return reduce(math.gcd, numbers)

k = int(input())
ans = 0
for a in range(1,k+1):
    for b in range(a, k+1):
        for c in range(b, k+1):
            if a == b and b == c:
                ans += gcd(a,b,c)
            elif (a == b and b != c) or (a != b and b == c):
                ans += gcd(a,b,c) * 3
            elif a != b and b != c:
                ans += gcd(a,b,c) * 6
            else:
                print('error')
print(ans)