import time
N = int(input())
A = list(map(int, input().split()))
Q = int(input())
BC = [list(map(int, input().split())) for _ in range(Q)]

num = [0] * 100010
for i in A:
    num[i] += 1
s = sum(A)

for i in range(Q):
    p, n = BC[i][0], BC[i][1]
    s += (n - p) * num[p]
    num[n] += num[p]
    num[p] = 0
    print(s)