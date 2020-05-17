import math

a, b, h, m = map(int, input().split())

ang_a = 30 * h + m / 2
ang_b = 6 * m
ang_c = max(ang_a, ang_b) - min(ang_a, ang_b)
if ang_c > 180: ang_c = 360 - ang_c
ans = math.sqrt(a**2 + b**2 - 2*a*b*math.cos(math.radians(ang_c)))
print(ans)
