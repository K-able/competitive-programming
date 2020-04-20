n, k = map(int, input().split())
mod = 10**9 + 7

ans = 0
for i in range(k, n+2): 
    a = 0.5 * i * (i - 1)
    b = 0.5 * i * (2 * n - i + 1)
    ans += (b - a + 1)
print(int(ans % mod))