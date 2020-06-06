import math
def lcm(a, b):
    return a // math.gcd(a, b) * b

N, M = map(int, input().split())
A = list(map(int, input().split()))

A_half = [a // 2 for a in A]
A_lcm = A_half[0]

for i in range(1, N):
    A_lcm = lcm(int(A_lcm), int(A_half[i]))
    
for i in A_half:
    if A_lcm // i % 2 == 0:
        print(0)
        exit()
ans = (M // A_lcm + 1) // 2
print(int(ans))