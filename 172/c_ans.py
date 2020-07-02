import bisect

N, M, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

Ac = [0]*(N+1)
Bc = [0]*(M+1)
for i in range(1, N+1):
    Ac[i] = Ac[i-1] + A[i-1]
for j in range(1, M+1):
    Bc[j] = Bc[j-1] + B[j-1]

ans = 0
for i in range(N+1):
    n = K - Ac[i]
    if n < 0: break
    tmp = bisect.bisect_right(Bc, n) - 1
    ans = max(ans, i + tmp)
    print(i, tmp, ans, n, Ac, Bc)
print(ans)