import math, random

def recover_factors(n, e, d):
    k = e * d - 1
    s, t = 0, k
    while t % 2 == 0:
        s += 1
        t //= 2
    for _ in range(100):
        a = random.randint(2, n - 2)
        v = pow(a, t, n)
        if v in (1, n - 1):
            continue
        for _ in range(s - 1):
            vo = v
            v = pow(v, 2, n)
            if v == n - 1:
                break
            if v == 1:
                p = math.gcd(vo - 1, n)
                return p, n // p
    return None, None

n, e, d_leaked = 3599, 31, 3031
p, q = recover_factors(n, e, d_leaked)
print(f"Modulus n: {n}")
print(f"Recovered factors from leaked d: p = {p}, q = {q}")
print("Conclusion: Reusing n is unsafe; p and q are exposed.")