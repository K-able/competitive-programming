from collections import Counter

n = int(input())
s_list = []

for i in range(n):
    s_list.append(input())

c = Counter(s_list)
l = c.most_common()    
count = l[0][1]
l.sort()
for i in l:
    if count == i[1]:
        print(i[0])