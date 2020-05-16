n, m = map(int, input().split())
sc_list = [list(input().split()) for _ in range(m)]
ans = -1
for i in range(10**n):
    if len(str(i)) != n:
        continue
    else:
        count = 0
        s = str(i)
        for sc in sc_list:
            if s[int(sc[0])-1] == sc[1]: 
                count += 1
        if count == m:
            ans = i
            break
print(ans)