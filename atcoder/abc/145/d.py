def bigcmb(N, R, MOD):
    if (R < 0) or (N < R):
        return 0
    R = min(R, N - R)
    fact, inv = 1, 1
    for i in range(1, R + 1):
        fact = (fact * (N - i + 1)) % MOD
        inv = (inv * i) % MOD
    return fact * pow(inv, MOD - 2, MOD) % MOD

X, Y = map(int, input().split())
if (X + Y) % 3 != 0:
    print(0)
    exit()

mod = 10**9 + 7
count = (X + Y) // 3
ans = bigcmb(count, X - count, mod)
print(ans)