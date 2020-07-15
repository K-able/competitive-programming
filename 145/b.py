N = int(input())
S = input()
if N % 2 == 0:
    T = N // 2
    if S[:T] == S[T:]:
        print('Yes')
    else:
        print('No')
else:
    print('No')