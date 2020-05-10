import sys
n, k = map(int,input().split())
a = [int(x) for x in input().split()]

vis_ti = [-1] * n
vis_at = [0]
now = 0

for i in range(1, k+1):
  now = a[now] - 1
  if vis_ti[now] >= 0:
    bgn = vis_ti[now]
    print(vis_at[bgn + (k - bgn) % (i - bgn)] + 1)
    sys.exit()
  vis_ti[now] = i
  vis_at.append(now)

print(vis_at[-1]+1)

'''
n, k = map(int, input().split())
a_list = list(map(int, input().split()))

num_list = []
visit = [-1] * n
next_to = -1
a, b = [0, 0]

for i in range(n):
    if i == 0:
        visit[0] = i
        num_list.append(1)
        next_to = a_list[i]
    else:
        if visit[next_to - 1] != -1:
            a = visit[next_to - 1]
            b = i - a
            break
        else:
            visit[next_to - 1] = i
            num_list.append(next_to)
            next_to = a_list[next_to - 1]
num_list = num_list[a:]
print(num_list[(k - a) % b])
'''
