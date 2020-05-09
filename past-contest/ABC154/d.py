n, k = map(int, input().split()) 
p_list = list(map(int, input().split()))
e_list = [(p + 1) / 2 for p in p_list]

s = sum(e_list[:k])
ans = s
for i, e in enumerate(e_list[k:]):
    s = s - e_list[i] + e
    ans = max(ans, s)
print(ans)