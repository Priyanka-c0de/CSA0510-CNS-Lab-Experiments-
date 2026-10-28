from sympy import factorint, mod_inverse

n = 3599
e = 31

factors = factorint(n)
p, q = factors.keys()

phi = (p - 1) * (q - 1)
d = mod_inverse(e, phi)

print("p =", p)
print("q =", q)
print("Phi(n) =", phi)
print("Private key d =", d)