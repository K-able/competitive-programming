# 原因不明のREで通らない
N, Q = map(int, input().split())
connect = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    connect[a].append(b)
    connect[b].append(a)
score = [0] * N
for _ in range(Q):
    p, x = map(int, input().split())
    p -= 1
    score[p] += x

def dfs(now, prev = -1):
    for nx in connect[now]:
        if nx == prev: continue
        score[nx] += score[now]
        dfs(nx, now)

dfs(0)
print(*score)