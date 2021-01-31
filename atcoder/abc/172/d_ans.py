N = int(input())
ans = 0

for i in range(1, N+1):
    j = N // i
    ans += int(j * (j+1) * i / 2)
print(ans)