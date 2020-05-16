n, m = map(int, input().split())
h_list = list(map(int, input().split()))
m_dic = {}
for i in range(1, n+1):
    m_dic[i] = []
for i in range(m):
    a, b = map(int, input().split())
    m_dic[a].append(b)
    m_dic[b].append(a)

ans = 0
for i in range(1, n+1):
    good = True
    for j in m_dic[i]:
        if h_list[i-1] <= h_list[j-1]:
            good = False
            break
    if good: ans += 1
print(ans)