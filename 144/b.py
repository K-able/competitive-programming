N = int(input())

ans = 'No'
for i in range(1, 10):
    for j in range(1, 10):
        if N == i * j:
            ans = 'Yes'
            break
print(ans)