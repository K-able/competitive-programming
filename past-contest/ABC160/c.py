k, n = input().split()
a_list_org = list(map(int,input().split()))
a_list = []
for a in a_list_org:
    if a == a_list_org[0]:
        pre = a
        a_list.append(int(k) - a_list_org[-1] + a)
    else:
        a_list.append(a - pre)
        pre = a
a_list.remove(max(a_list))
print(sum(a_list))