X, N = map(int, input().split())
p = list(map(int, input().split()))

diff = 123456
ans = -1
for i in range(102):
    if i in p: continue
    if diff > i - X:
        diff = abs(i - X)
        ans = i
print(ans)