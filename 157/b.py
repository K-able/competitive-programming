a_list1, a_list2, a_list3 = [list(map(int,input().split())) for _ in range(3)]
n = int(input())
b_list = []
for _ in range(n):
    b_list.append(int(input()))
a_list = a_list1 + a_list2 + a_list3
hit_list = []
for i in range(len(a_list)):
    if a_list[i] in b_list:
        hit_list.append(i)
bingo_list = [[0,1,2],[3,4,5],[6,7,8],[0,3,6],[1,4,7],[2,5,8],[0,4,8],[2,4,6]]
ans = 'No'
for bingo in bingo_list:
    if set(bingo) <= set(hit_list):
        ans = 'Yes'
        break
print(ans)