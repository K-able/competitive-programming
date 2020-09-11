from itertools import combinations

N = int(input())
p = list(map(int, input().split()))

ans = 'NO'
p_sorted = list(sorted(p))
if p == p_sorted:
    ans = 'YES'
else:
    l = [i for i in range(N)]
    c = combinations(l, 2)
    for v in c:
        tmp = p.copy()
        tmp[v[0]], tmp[v[1]] = tmp[v[1]], tmp[v[0]]
        if tmp == p_sorted:
            ans = 'YES'
            break
print(ans)
