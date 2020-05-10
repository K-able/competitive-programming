import numpy as np

n, m, x = map(int, input().split())
ca_list = [list(map(int, input().split())) for _ in range(n)]

r_list = [x] * m
ans = 0

for i in range(n):
    if sum(r_list) == 0: break
    max_e = 0
    min_m = 0
    select = []
    index = -1
    for j, a in enumerate(ca_list):
        tmp = a[1:]
        for k, v in enumerate(tmp):
            if tmp[k] > r_list[k]: tmp[k] = r_list[k]
        if sum(tmp) / a[0] > max_e:
            max_e = sum(tmp) / a[0]
            min_m = a[0]
            select = tmp
            index = j
    ans += min_m
    r_list = list(np.array(r_list) - np.array(select))
    ca_list.pop(index)
if sum(r_list) != 0: ans = -1
print(ans)