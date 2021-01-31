s = input()
n = len(s)
if s == ''.join(list(reversed(s))) and s[:(n-1)//2] == ''.join(list(reversed(s[:(n-1)//2]))) and s[(n+3)//2-1:] == ''.join(list(reversed(s[(n+3)//2-1:]))):
    print('Yes')
else:
    print('No')