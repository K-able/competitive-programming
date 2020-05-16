n, k = map(int, input().split())
mod = 10**9 + 7

if n + 1 == k:
    print(1)
    exit()

n_list = [i for i in range(n+1)]
ans = 0
for i in range(k, n+2): 
    min_num = sum(n_list[:i])
    max_num = sum(n_list[-i:])
    ans += (max_num - min_num + 1)
print(ans % mod)
#TLE