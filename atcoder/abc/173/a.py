import math

N = int(input())
if N % 1000 == 0:
    print(0)
else:
    print(1000*math.ceil(N/1000)-N)