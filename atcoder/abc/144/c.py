N = int(input())

a, b = 0, 0
for i in range(int(N**(1/2)), 0, -1):
    if N % i == 0:
        a = i
        b = N / a
        break
print(int(a+b-2))