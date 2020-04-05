k = int(input())
no_runrun = False
ans = 0
if k < 10:
    print(k)
    exit()
else:
    k -= 9
for n in range(2,11):
    if k > 9 * (3 ** (n-1)) - (2 ** (3 * (n-2))):
        k -= 9 * (3 ** (n-1)) - (2 ** (3 * (n-2)))
    else:
        for i in range(10**(n-1), 10**n):
            num = [int(s) for s in list(str(i))]
            for x in range(len(num)-1):
                if abs(num[x]-num[x+1]) > 1:
                    no_runrun = True
                    break
            if not no_runrun:
                k -= 1
                ans = int(''.join(map(str, num)))
            no_runrun = False
            if k == 0:
                print(ans)
                exit()