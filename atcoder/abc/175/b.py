from itertools import combinations
N = int(input())
L = list(map(int, input().split()))
c = combinations(L, 3)

ans = 0
for v in c:
    a = v[0]
    b = v[1]
    c = v[2]
    if a != b and b != c and a != c:
        s = sum(v)
        m = max(a, b, c)
        if s > 2 * m:
            ans += 1
print(ans)
