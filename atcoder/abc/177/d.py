import queue

N, M = map(int, input().split())
AB = {}
for i in range(N): AB[i] = set()
for _ in range(M):
    A, B = map(int, input().split())
    A -= 1
    B -= 1
    AB[A].add(B)
    AB[B].add(A)

finish = [False] * N
q = queue.Queue()
ans = 0
for i in range(N):
    if finish[i]: continue
    q.put(i)
    group = set()
    while not q.empty():
        x = q.get()
        group.add(x)
        finish[x] = True
        for friend in AB[x]:
            if finish[friend]: continue
            q.put(friend)
            finish[friend] = True
    tmp = len(group)
    if tmp >= N / 2:
        ans = tmp
        break
    ans = max(ans, len(group))
print(ans)
