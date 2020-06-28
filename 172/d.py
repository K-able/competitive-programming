def divisors_count(n):
    i = 1
    c = 0
    while i*i <= n:
        if n % i == 0:
            c += 1
            if i != n // i:
                c += 1
        i += 1
    return c

N = int(input())
ans = 0
for i in range(1, N+1):
    ans += i * divisors_count(i)
print(ans)