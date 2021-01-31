def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append(cnt)
    if temp != 1:
        arr.append(1)

    if arr == []:
        if n == 1: arr.append(-1)
        else: arr.append(1)
    return arr

N = int(input())
fact = factorization(N)
ans = 0

for i in fact:
    if i == -1: break
    tmp = i
    for j in range(1, i+1):
        if tmp >= j:
            tmp -= j
            ans += 1
print(ans)