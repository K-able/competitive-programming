N, K = map(int, input().split())
P = list(map(int, input().split()))
C = list(map(int, input().split()))

ans = 0
for i in range(N):
    group = []
    p = P[i-1]
    while True:
        group.append(C[p-1])
        p = P[p-1]
        if p-1 == i: break
    s = sum(group)

'''
score = [[]]
s_g = 0
start = 1
score[s_g].append(C[0])
p = P[0]
r_list = [i for i in range(1, N+1)]
for _ in range(N-1):
    if p == start:
        r_list.remove(p)
        score.append([])
        s_g += 1
        start = r_list[0]
        p = P[start-1]
    else:
        r_list.remove(p)
        score[s_g].append(C[p-1])
        p = P[p-1]
'''
