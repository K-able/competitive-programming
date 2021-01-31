import itertools

N = int(input())
P = list(input().split())
Q = list(input().split())
p = itertools.permutations(P)

P = int(''.join(P))
Q = int(''.join(Q))

a = 0
b = 0
for v in p:
    if P >= int(''.join(v)): a += 1
    if Q >= int(''.join(v)): b += 1
print(abs(a - b))