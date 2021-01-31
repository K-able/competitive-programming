N = int(input())
s = [input() for _ in range(N)]
c0, c1, c2, c3 = s.count('AC'), s.count('WA'), s.count('TLE'), s.count('RE')
print('AC x', c0)
print('WA x', c1)
print('TLE x', c2)
print('RE x', c3)