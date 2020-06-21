N = int(input())
base = ord('a')
r = []
q = N
for i in range(12):
    if q <= 26:
        r.append(q)
        break
    if q % 26 == 0:
        r.append(26)
        q = q // 26 - 1
    else:
        r.append(q % 26)
        q = q // 26
r.reverse()
ans = [chr(i+base-1) for i in r]
print(''.join(ans))