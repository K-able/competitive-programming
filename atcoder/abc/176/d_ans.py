from collections import deque

h, w = map(int, input().split())
si, sj = map(int, input().split())
ti, tj = map(int, input().split())
s = [input() for _ in range(h)]
si -= 1
sj -= 1
ti -= 1
tj -= 1

INF = 10**9
di = [-1, 0, 1, 0]
dj = [0, -1, 0, 1]
dist = [[INF] * w for _ in range(h)]
q = deque()
dist[si][sj] = 0
q.appendleft([si, sj])

while q:
    i, j = q.popleft()
    d = dist[i][j]
    for v in range(4):
        ni = i + di[v]
        nj = j + dj[v]
        if ni < 0 or ni >= h or nj < 0 or nj >= w: continue
        if s[ni][nj] == '#': continue
        if dist[ni][nj] <= d: continue
        dist[ni][nj] = d
        q.appendleft([ni, nj])
    for ei in range(-2, 3):
        for ej in range(-2, 3):
            ni = i + ei
            nj = j + ej
            if ni < 0 or ni >= h or nj < 0 or nj >= w: continue
            if s[ni][nj] == '#': continue
            if dist[ni][nj] <= d+1: continue
            dist[ni][nj] = d+1
            q.append([ni, nj])

ans = dist[ti][tj]
if ans == INF: ans = -1
print(ans)
