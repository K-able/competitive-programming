N = list(map(int, input().split()))
s = sum(N)
print('Yes' if s % 9 == 0 else 'No')
