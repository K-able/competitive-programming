from decimal import *

A, B = input().split()

ans = Decimal(A) * Decimal(B)
ans = ans.quantize(Decimal('0'), rounding=ROUND_DOWN)
print(ans)