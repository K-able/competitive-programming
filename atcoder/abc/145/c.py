import itertools
import math

N = int(input())
xy = [list(map(int, input().split())) for _ in range(N)]

p = itertools.permutations(xy, N)
ans = 0
for v in p:
    for i in range(N-1):
        ans += math.sqrt((v[i][0]-v[i+1][0])**2 + (v[i][1]-v[i+1][1])**2)
ans /= math.factorial(N)
print(ans)