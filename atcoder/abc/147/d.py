N = int(input())
A = list(map(int, input().split()))

mod = 10**9+7
ans = 0
for j in range(60):
    one_num = 0
    for i in A:
        if (i >> j) & 1:
            one_num += 1
    ans += one_num * (N - one_num) * 2**j
    ans %= mod
print(ans)