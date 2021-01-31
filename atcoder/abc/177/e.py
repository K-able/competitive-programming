from math import gcd

def fact(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i ==0:
            while temp % i == 0:
                temp //= i
            arr.append(i)
    if temp != 1:
        arr.append(temp)
    if arr == []:
        arr.append(n)
    return arr

N = int(input())
A = list(map(int, input().split()))

flg = [False] * 10**6
ans = 'not coprime'
f = False
for i in A:
    if f: break
    prime = fact(i)
    for j in prime:
        if flg[j] == True:
            f = True
            break
if not f:
    ans = 'pairwise coprime'
else:
    g = A[0]
    for i in range(1, N):
        g = gcd(g, A[i])
        if g == 1:
            ans = 'setwise coprime'
            break
print(ans)





