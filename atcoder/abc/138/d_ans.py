from collections import deque
 
N, Q = map(int, input().split())
Ki = [[] for _ in range(N)]
for _ in range(N-1):
    p, c = map(int, input().split())
    Ki[p-1].append(c-1)
    Ki[c-1].append(p-1)
S = [0]*N
for _ in range(Q):
    node, score = map(int, input().split())
    S[node-1] += score
 
stack = deque([0])
done = [0]*N
done[0] = 1
 
while len(stack) > 0:
    now = stack.pop()
    
    for new in Ki[now]:
        if done[new] == 0:
            done[new] = 1
            stack.append(new)
            S[new] += S[now]
    
print(*S)