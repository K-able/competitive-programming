n, m = map(int, input().split())

l = [i for i in range(1,n+1)]
for i in range(m):
    print(l[i], l[-(i+1)])