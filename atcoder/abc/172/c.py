import numpy

def get_index(l, n):
    tmp = [x for x in l if x <= n]
    return len(tmp)

N, M, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

Ac = numpy.cumsum(A)
Bc = numpy.cumsum(B)

ans = 0
for i in range(len(Ac)):
    n = K - Ac[i]
    if n < 0: break
    ans = i + 1
    ans += get_index(Bc, n)
ans = max(ans, get_index(Ac, K), get_index(Bc, K))
print(ans)