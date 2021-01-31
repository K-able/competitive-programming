import bisect

N = int(input())
L = list(map(int, input().split()))

L.sort()
ans = 0
for i in range(N-1, 1, -1):
    for j in range(i-1, 0, -1):
        a, b = L[i], L[j]
        c = a - b + 1
        if c > b: continue
        ans += (j - bisect.bisect_left(L, c))
print(ans)