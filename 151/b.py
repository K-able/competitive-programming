n, k, m = map(int, input().split())
a_list = list(map(int, input().split()))

a_sum = sum(a_list)
target_sum = n * m

if a_sum + k < target_sum:
    print(-1)
elif a_sum >= target_sum:
    print(0)
else:
    print(target_sum - a_sum)