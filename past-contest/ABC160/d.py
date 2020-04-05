import collections

def distances(n,x,y):
    for i in range(1, int(n)):
        for j in range(i+1, int(n)+1):
            yield min(abs(i-j), abs(i-x)+abs(j-y)+1, abs(i-y)+abs(j-x)+1)

n, x, y = map(int, input().split())

c = collections.Counter(distances(n,x,y))

for i in range(1,n):
    print(c[i])