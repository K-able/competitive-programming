n, m = map(int, input().split())
a_list = list(map(int, input().split()))

a_list.sort(reverse=True)
if len(a_list) < m:
    print('No')
all_vote = sum(a_list)
a_list = a_list[:m]
if a_list[-1] < (all_vote / (4 * m)):
    print('No')
else:
    print('Yes')
