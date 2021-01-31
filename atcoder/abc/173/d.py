N = int(input())
A = list(map(int, input().split()))

A.sort(reverse=True)
ans = 0
for i in range(1, N):
    index = i // 2
    ans += A[index]
print(ans)