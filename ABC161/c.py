n, k = map(int, input().split())
ans = 0
if n < k:
    ans = min(n, abs(n-k))
else:
    if n % k == 0:
        ans = 0
    else:
        n = n % k
        ans = min(n, abs(n-k))
print(ans)
