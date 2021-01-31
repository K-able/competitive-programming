x = int(input())

n = 100
ans = 0
for i in range(1, 10**4):
    n *= 1.01
    n *= 10
    n = n // 10
    if n >= x:
        ans = i
        break
print(ans)