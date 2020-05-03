n, k = map(int, input().split())
a = set()
for i in range(k):
    d = int(input())
    tmp = set(list(map(int, input().split())))
    a = a.union(tmp)
print(n - len(a))