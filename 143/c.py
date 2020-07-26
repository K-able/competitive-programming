N = int(input())
S = input()

ans = 0
pre = ''
for i in range(N):
    if pre != S[i:i+1]: ans += 1
    pre = S[i:i+1]
print(ans)