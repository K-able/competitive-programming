s = input()
q = int(input())
query_list = [list(input().split()) for _ in range(q)]
reverse_flag = False
concat = ''
initial = 0
for query in query_list:
    if query[0] == '1':
        reverse_flag = not reverse_flag
    elif query[0] == '2':
        if (query[1] == '1' and not reverse_flag) or (query[1] == '2' and reverse_flag):
            concat = query[2] + concat
            initial += 1
        elif (query[1] == '2' and not reverse_flag) or (query[1] == '1' and reverse_flag):
            concat = concat + query[2]
ans = ''
if reverse_flag:
    s = s[::-1]
    concat = concat[::-1]
    ans = concat[:-initial]+s+concat[-initial:]
else:
    ans = concat[:initial]+s+concat[initial:]
print(ans)