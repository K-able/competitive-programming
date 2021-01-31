import heapq

N, M = map(int, input().split())
A = list(map(lambda x: int(x)*(-1), input().split()))
heapq.heapify(A)
for _ in range(M):
    tmp = heapq.heappop(A)
    heapq.heappush(A, (-1)*(-tmp//2))
print(-sum(A))