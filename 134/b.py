N, D = map(int, input().split())
r = 2 * D + 1
print(N // r if N % r == 0 else N // r + 1)
