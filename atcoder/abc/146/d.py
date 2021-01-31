from collections import deque

N = int(input())
graph = [[] for _ in range(N)]

for i in range(N-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append([b, i])
    graph[b].append([a, i])

ans = [0] * (N - 1)
q = deque([[1, 0, -1]])
while q:
    node, pcol, p_node = q.popleft()
    cnt = 1
    for n_node in graph[node]:
        if n_node[0] == p_node: continue
        if cnt == pcol: cnt += 1
        ans[n_node[1]] = cnt
        q.append([n_node[0], cnt, node])
        cnt += 1
print(max(ans))
print(*ans, sep="\n")