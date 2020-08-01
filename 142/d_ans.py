from fractions import gcd
def factorization(n):
    fac = {}
    count = 0
    while n % 2 == 0:
        n //= 2
        count += 1
    if count > 0:
        fac[2] = count
    for i in range(3, int(n ** .5) + 1, 2):
        count = 0
        while n % i == 0:
            n //= i
            count += 1
        if count > 0:
            fac[i] = count
    if n > 1:
        fac[n] = 1
    return fac

A, B = map(int, input().split())
fac = factorization(gcd(A, B))
print(len(fac) + 1)
