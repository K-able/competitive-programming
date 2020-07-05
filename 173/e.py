N, K = map(int, input().split())
A = list(map(int, input().split()))
A.sort(reverse=True)
B = A[:K]

x = 0
for i in range(len(B)):
    x *= B[i]

ans = x % (10**9+7)
print(ans)