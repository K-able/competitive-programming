from scipy.special import comb

n, a, b = map(int, input().split())
ans = (pow(2, n) - 1) % (10**9+7)
#ans -= (comb(n,a) + comb(n,b))
#ans %= (10**9+7)
print(int(ans))