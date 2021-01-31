a, b = map(int, input().split())
if a <= b:
    print(''.join([str(a) for _ in range(b)]))
else:
    print(''.join([str(b) for _ in range(a)]))