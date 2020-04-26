s = input()
ans = 0
l = len(s)
'''
for i in range(1, 10**l//2019+2):
    if '0' in str(2019*i): continue
    ans += s.count(str(2019*i))
print(ans)
'''

for i in range(l - 3):
    if int(s[i:i+2]) % 2 != 0:
        continue
    else:
        for j in range(i + 4, l + 1):
            sub_s = int(s[i:j])
            if sub_s % 2019 == 0: ans += 1
print(ans)