mod = 10**9+7

def calculate_combination(n,k):
    x, y = 1, 1
    for i in range(k):
        x *= (n - i) % mod
        y *= (k - i) % mod
    return x * pow(y, mod-2, mod) % mod

n, a, b = map(int, input().split())

ans = pow(2, n, mod) - 1 - calculate_combination(n,a) - calculate_combination(n,b)
while ans < 0:
    ans += mod
print(ans)