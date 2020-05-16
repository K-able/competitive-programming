n, m = map(int, input().split())
ps_list = [list(input().split()) for _ in range(m)]

ans_dic = {}
pen_dic = {}
for ps in ps_list:
    p = int(ps[0])
    ans_dic[p] = 0
    pen_dic[p] = 0
ans = 0
pen = 0

for ps in ps_list:
    p, s = ps
    p = int(p)
    if s == 'AC':
        if ans_dic[p] == 0:
            ans += 1
            pen += pen_dic[p]
        ans_dic[p] = 1
    elif s == 'WA':
        pen_dic[p] += 1

print(ans, pen)