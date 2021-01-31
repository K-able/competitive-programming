N = int(input())
A = [int(input()) for _ in range(N)]

A_sorted = list(sorted(A))
m = A_sorted[-1]
s = A_sorted[-2]
if m == s:
    for i in range(N): print(m)
else:
    for i in range(N):
        if m != A[i]: print(m)
        else: print(s)
