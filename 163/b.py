n, m = map(int, input().split())
a_list = list(map(int, input().split()))
a_sum = sum(a_list)
if a_sum > n:
    print(-1)
else:
    print(n - a_sum)