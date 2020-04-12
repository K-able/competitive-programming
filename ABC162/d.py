n = int(input())
s = input()

rgb = 'RGB'
ans = 0
for i in range(0, n-2):
    for j in range(i+1,n-1):
        if s[i] == s[j]: continue
        k = rgb[:rgb.find(s[i])] + rgb[rgb.find(s[i])+1:]
        k = k[:k.find(s[j])] + k[k.find(s[j])+1:]
        r = s[j+1:2*j-i] + s[2*j-i+1:]
        ans += r.count(k)
print(ans)