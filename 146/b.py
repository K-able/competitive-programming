N = int(input())
S = input()
for s in S:
    asc = ord(s) + N
    if asc > 90: asc -= 26
    print(chr(asc), end='')