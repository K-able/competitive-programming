H, W, K = map(int, input().split())
c = [list(input()) for _ in range(H)]
digit = H + W
sum_b = 0
for x in c:
    sum_b += x.count('#')

brack = []
for i in range(H):
    for j in range(W):
        if c[i][j] == '#':
            brack.append(int(str(10**(H+j)+10**i).zfill(digit), 2))

ans = 0
for i in range(2**digit):
    tmp = 0
    for j in brack:
        if i & j != 0: tmp += 1
    if sum_b - tmp == K: ans += 1    
print(ans)