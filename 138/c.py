from collections import deque
N = int(input())
v = list(map(int, input().split()))

v.sort()
q = deque(v)
for i in range(N-1):
    x, y = q.popleft(), q.popleft()
    q.appendleft((x + y) / 2)
print(q.pop())