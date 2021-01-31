H, W = map(int, input().split())
Ch, Cw = map(int, input().split())
Dh, Dw = map(int, input().split())
S = [input() for _ in range(H)]
H -= 1
W -= 1
Ch -= 1
Cw -= 1
Dh -= 1
Dw -= 1

dw = [0, 1, 0, -1]
dh = [1, 0, -1, 0]
finish = [[False] * (W + 1)] * (H + 1)
d = 10**10
p = []
def dfs(w, h):
    finish[w][h] = True
    tmp = (Dw - w) + (Dh - h)
    if tmp < d:
        d = tmp
        p += [w, h]
    for i in range(4):
        nw = w + dw[i]
        nh = h + dh[i]
        if nw < 0 or nw > W or nh < 0 or nh > H: continue
        if S[nw][nh] == '#': continue
        if finish[nw][nh]: continue
        dfs(nw, nh)

for _ in range(10):
    dfs(Cw, Ch)
    if finish[Dw][Dh]: break
    # warp
