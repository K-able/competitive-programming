n = int(input())
x_list = list(map(int, input().split()))
ans = 10**8
for p in range(1,101):
    d = 0
    for i in x_list:
        d += (i-p)**2
    ans = min(ans, d)
print(ans)