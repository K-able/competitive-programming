from collections import Counter

N, K, Q = map(int, input().split())
A = [int(input()) for _ in range(Q)]

c = Counter(A)
for i in range(N):
    if K - (Q - c[i+1]) > 0:
        print('Yes')
    else:
        print('No')