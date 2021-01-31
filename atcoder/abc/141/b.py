S = list(input())
S_odd = [s for i, s in enumerate(S) if i % 2 == 0]
S_even = [s for i, s in enumerate(S) if i % 2 != 0]
if 'L' in S_odd or 'R' in S_even:
    print('No')
else:
    print('Yes')