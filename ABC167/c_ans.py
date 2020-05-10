import numpy as np

n, m, x = map(int, input().split())
ca_list = [list(map(int, input().split())) for _ in range(n)]

ans = 10**7
for i in range(2**n):
    select_list = list(map(int, format(i, '0'+str(n)+'b')))
    tmp = []
    r = np.array([x] * m)
    money = 0
    c = True
    for i, ca in enumerate(ca_list):
        if select_list[i]:
            r -= np.array(ca[1:])
            money += ca[0]
    for i in r:
        if i > 0: c = False
    if c:
        ans = min(ans, money)
if ans == 10**7:
    print(-1)
else:
    print(ans)
