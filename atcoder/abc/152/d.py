n = int(input())

c = [[0 for _ in range(10)] for _ in range(10)]

for k in range(1, n+1):
    i = int(str(k)[0])
    j = int(str(k)[-1])
    c[i][j] += 1

ans = 0
for i in range(10):
    for j in range(10):
        ans += c[i][j] * c[j][i]
print(ans)