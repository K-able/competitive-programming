from math import gcd

def get_primes(n):
    is_prime = [True] * (n+1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(n**0.5)+1):
        if not is_prime[i]: continue
        for j in range(i*2, n+1, i):
            is_prime[j] = False
    return [i for i in range(n+1) if is_prime[i]]

def factorization_num(n, pl):
    count = 0
    for p in pl:
        if n % p == 0: count += 1
    return count

A, B = map(int, input().split())
print(factorization_num(gcd(A, B), get_primes(gcd(A, B))) + 1)