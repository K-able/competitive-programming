n = int(input())
p_list = list(map(int, input().split()))

ans = 0
m = 10**10

for p in p_list:
    if p <= m:
        ans += 1
        m = p
print(ans)