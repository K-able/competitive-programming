x = int(input())
for a in range(10**3):
    for b in range(10**3):
        if a**5 - b**5 == x: 
            print(a, b)
            exit()
        elif a**5 + b**5 == x:
            print(a, -b)
            exit()
print('error')