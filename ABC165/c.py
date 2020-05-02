import itertools

n, m, q = map(int, input().split())
q_list = []
for i in range(q):
    q_list.append(list(map(int, input().split())))

l = [i for i in range(1, m+1)]
comb = itertools.combinations_with_replacement(l, n)

ans = 0
for v in comb:
    tmp = 0
    for d in q_list:
        if v[d[1]-1] - v[d[0]-1] == d[2]: tmp += d[3]
    ans = max(ans, tmp)
print(ans)