N, K = map(int, input().split())
P = list(map(int, input().split()))
C = list(map(int, input().split()))
P = [i - 1 for i in P]

ans = -10**18
for si in range(N):
    x = si
    s = []
    total = 0
    while True:
        x = P[x]
        s.append(C[x])
        total += C[x]
        if x == si: break
    l = len(s)
    t = 0
    for i in range(l):
        t += s[i]
        if i + 1 > K: break
        now = t
        if total > 0:
            e = (K - (i + 1)) // l
            now += total * e
        ans = max(ans, now)
print(ans)
