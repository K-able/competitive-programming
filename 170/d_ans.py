from numba import njit

N = int(input())
A = list(map(int, input().split()))
maxA = max(A)
dp = [0] * maxA

for i in range(N):
    if dp[A[i]-1] != 0:
        dp[A[i]-1] = 2
        continue
    else:
        for j in range(1, maxA//A[i]+1):
            dp[A[i]*j-1] += 1

ans = 0
for i in range(N):
    if dp[A[i]-1] == 1:
        ans += 1

print(ans)