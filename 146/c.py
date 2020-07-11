A, B, X = map(int, input().split())

low = 0
high = 10**9+1
while high - low > 1:
    mid = (low + high) // 2
    if A * mid + B * len(str(mid)) <= X:
        low = mid
    else:
        high = mid
print(low)