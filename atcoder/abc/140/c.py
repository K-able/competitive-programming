N = int(input())
B = list(map(int, input().split()))

if len(B) == 1:
    print(B[0]*2)
    exit()
else:
    ans = B[0]
    for i in range(len(B)-1):
        ans += min(B[i], B[i+1])
    ans += B[-1]
print(ans)
