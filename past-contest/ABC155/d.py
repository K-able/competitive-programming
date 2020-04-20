'''
n = int(input())
s_dic = {}
for i in range(n):
    s = input()
    if s not in s_dic:
        s_dic[s] = 1
    else:
        s_dic[s] += 1
max_s_list = [s[0] for s in s_dic.items() if s[1] == max(s_dic.values())]
max_s_list.sort()
for s in max_s_list:
    print(s)
'''