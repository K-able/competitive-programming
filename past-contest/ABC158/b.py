n, a, b = map(int, input().split())
ans = a * (n // (a+b))
if n % (a+b) > a:
    ans += a
else:
    ans += n % (a+b)
print(ans)