n = int(input())
s = input()

r = s.count('R')
g = s.count('G')
b = s.count('B')

count = 0
#count second conditions satisfied
for i in range(n):
    for j in range(i+1,n):
        #search j - i = k - j ⇔ k = 2 * j - i
        k = 2 * j - i
        if k >= n: break
        if s[i] != s[j] and s[j] != s[k] and s[i] != s[k]: count += 1
print((r * g * b) - count)