import heapq

N, M = map(int, input().split())

AB = [[] for _ in range(M)]
for _ in range(N):
    a, b = map(int, input().split())
    if a > M: continue
    AB[M-a].append(b)

q = []
heapq.heapify(q)
ans = 0
for i in range(M-1, -1, -1):
    if len(AB[i]) != 0:
        for b in AB[i]:
            heapq.heappush(q, -b)
    if len(q) != 0:
        ans += heapq.heappop(q)
print(-ans)