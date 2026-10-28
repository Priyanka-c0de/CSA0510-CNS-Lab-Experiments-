import math

n = 3599
e = 31
# Plaintext message sharing factor with n
plaintext_block = 590 

factor = math.gcd(plaintext_block, n)
print(f"gcd(plaintext, n): {factor}")

if 1 < factor < n:
    p = factor
    q = n // p
    phi = (p - 1) * (q - 1)
    d = pow(e, -1, phi)
    print(f"System Broken! Factors: p={p}, q={q}")
    print(f"Private Key d = {d}")