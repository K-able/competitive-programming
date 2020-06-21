import time
N = int(input())
A = list(map(int, input().split()))
Q = int(input())
BC = [list(map(int, input().split())) for _ in range(Q)]

start = time.time()
for i in range(Q):
    p, n = BC[i][0], BC[i][1]
    A = [x if x != p else n for x in A]
    #A = list(map(str, A))
    #A = [s.replace(str(p), str(n)) for s in A]
    #A = list(map(int, A))
    print(sum(A))
end = time.time()

print((end-start)*1000)