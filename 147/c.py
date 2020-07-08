N = int(input())
A = {}

for i in range(N):
    num = int(input())
    tmp = [list(map(int, input().split())) for _ in range(num)]
    A[i] = tmp

ans = 0
# bit: pattern of honest 1 and unkind 0
for bit in range(2**N):
    tmp = bit
    flag = True
    # check
    for i in range(N):
        if not (bit >> i & 1):  # case of unkind => continue
            continue
        # case of honest
        for x, y in A[i]:
            if (bit >> (x - 1) & 1) != y:   # check if really honest
                flag = False
                break
    if flag:
        ans = max(ans, bin(bit).count("1"))
print(ans)