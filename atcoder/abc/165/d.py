import math

a, b, n = map(int, input().split())
x = min(b-1, n)
ans = math.floor(a * x / b) - a * math.floor(x / b)
print(ans)