import collections

n = int(input())
a_list = list(map(int, input().split()))
c = collections.Counter(a_list)
ans = 0
for i in c.values():
    ans += i*(i-1)//2
for i in range(n):
    print(ans - (c[a_list[i]]-1))