class UnionFind():
    def __init__(self, n):
        self.n = n
        self.root = [-1]*(n+1)
        self.rnk = [0]*(n+1)
    
    def Find_Root(self, x):
        if self.root[x] < 0:
            return x
        else:
            self.root[x] = self.Find_Root(self.root[x])
            return self.root[x]
    
    def Unite(self, x, y):
        x = self.Find_Root(x)
        y = self.Find_Root(y)
        if x == y:
            return 
        elif self.rnk[x] > self.rnk[y]:
            self.root[x] += self.root[y]
            self.root[y] = x
        else:
            self.root[y] += self.root[x]
            self.root[x] = y
            if self.rnk[x] == self.rnk[y]:
                self.rnk[y] += 1
    
    def isSameGroup(self, x, y):
        return self.Find_Root(x) == self.Find_Root(y)
 
    def Count(self, x):
        return -self.root[self.Find_Root(x)]

N,M,K = list(map(int,input().split()))

uf = UnionFind(N)
fr = [0]*(N+1)

for i in range(M):
    [x_tmp,y_tmp] = list(map(int,input().split()))
    uf.Unite(x_tmp,y_tmp)
    fr[x_tmp] += 1
    fr[y_tmp] += 1

ans = [0]*(N+1)

for i in range(1,N+1):
    ans[i] = uf.Count(i) - fr[i] - 1
for j in range(K):
    [x_tmp,y_tmp] = list(map(int,input().split()))
    if uf.isSameGroup(x_tmp,y_tmp):
        ans[x_tmp] -= 1
        ans[y_tmp] -= 1

print(' '.join(list(map(str,ans[1:]))))