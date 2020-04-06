import math
n, k = map(int, input().split())
ans = int(math.log(n, k))+1
print(ans)