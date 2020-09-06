N = int(input())
H = list(map(int, input().split()))

flg = True
for i in range(N-2, 0, -1):
    if H[i] - 1 > H[i+1]:
        flg = False
        break
    else:
        if H[i] > H[i+1]: H[i] -= 1
if flg:
    print('Yes')
else:
    print('No')
