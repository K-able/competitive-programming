from collections import Counter

n = int(input())
a_list = list(map(int, input().split()))
c = Counter(a_list)
for i in range(1, n+1):
    print(c[i])