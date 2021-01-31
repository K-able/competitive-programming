A, B = map(int, input().split())

for i in range(100):
    if 1 + (A-1) * i >= B: break
print(i)