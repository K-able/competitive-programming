N = int(input())
A = list(map(int, input().split()))

dicA =  {}
for i in range(1, N+1):
    dicA[i] = A[i-1]

sort_dicA = sorted(dicA.items(), key=lambda x:x[1])
for i in range(N):
    print(sort_dicA[i][0], end=' ')
