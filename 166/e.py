import itertools

n = int(input())
a_list = list(map(int, input().split()))
n_list = [i for i in range(n)]

ans = 0
for i in range(1, n):
    d_list = n_list[0:-i]
    h_list = a_list[0:-i] + [a_list[i]] * (n - i - 1)
    print(d_list)
    print(h_list)
'''
for i in range(1, n):
    for j in range(i+a_list[i-1]+1, n+1):
        if abs(i - j) == (a_list[i-1] + a_list[j-1]): ans += 1
print(ans)

n_list = [i for i in range(n)]
comb = itertools.combinations(n_list, 2)
ans = 0

for c in comb:
    if abs(c[0] - c[1]) == (a_list[c[0]] + a_list[c[1]]): ans += 1

print(ans)
'''