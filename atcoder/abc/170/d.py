def quick_sort(arr):
    left = []
    right = []
    if len(arr) <= 1:
        return arr
    ref = arr[0]
    ref_count = 0
    for ele in arr:
        if ele < ref:
            left.append(ele)
        elif ele > ref:
            right.append(ele)
        else:
            ref_count += 1
    left = quick_sort(left)
    right = quick_sort(right)
    return right + [ref] * ref_count + left

N = int(input())
A = list(map(int, input().split()))

A = [x for x in A if A.count(x) == 1]
A = quick_sort(A)

ans = 0
if len(A) == 0:
    print(ans)
    exit()
for i in range(N):
    flag = True
    for j in range(i+1, N):
        if A[i] % A[j] == 0:
            flag = False
            break
    if flag: ans += 1
print(ans)