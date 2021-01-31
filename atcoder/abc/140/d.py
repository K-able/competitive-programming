N, K = map(int, input().split())
S = input()

ans = N - 1
initial = 0
for i in range(N-1):
    if S[i] == S[i+1]: initial += 1
ans = min(ans, initial + 2 * K)
print(ans)