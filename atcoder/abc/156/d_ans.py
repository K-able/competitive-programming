mod = 10 ** 9 + 7

def calc(n,r):
    x = 1
    y = 1
    for i in range(r):
        x *= n - i
        x %= mod
        y *= i + 1
        y %= mod
    return x * pow(y, mod - 2, mod) % mod

n, a, b = map(int, input().split())
res = pow(2, n, mod) - 1
 
for i in [a, b]:
    res -= calc(n, i)
print(res % mod)