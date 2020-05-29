# BFS
from collections import deque

h, w = map(int, input().split())
s = [input() for _ in range(h)]

ans = 0

for i in range(h):
    for j in range(w):
        if s[i][j] == '#': continue
        q = deque([(i, j)])
        dist = [[-1]*w for _ in range(h)]
        dist[i][j] = 0
        while q:
            x, y = q.popleft()
            for k, l in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                if 0 <= x+k < h and 0 <= y+l < w and dist[x+k][y+l] < 0 and s[x+k][y+l] == '.':
                    dist[x+k][y+l] = dist[x][y] + 1
                    ans = max(ans, dist[x+k][y+l])
                    q.append((x+k, y+l))
print(ans)