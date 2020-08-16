X, K, D = map(int, input().split())
DK = D * K

ans = 0
if DK <= abs(X):
    ans = abs(X) - DK
else:
    q = X // D
    r = X % D
    if (K - q) % 2 == 0:
        ans = r
    else:
        ans = D - r
print(ans)
