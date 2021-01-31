N = int(input())
a = list(map(int, input().split()))

count = 1
if 1 not in a:
    print(-1)
    exit()
for i in range(N):
    if count == a[i]: count += 1
print(N-count+1)