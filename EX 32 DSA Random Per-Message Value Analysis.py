p, q, g = 59, 29, 3  # Small prime parameters
x = 7                # Private key
H_m = 15             # Fixed message hash

def sign(k):
    r = pow(g, k, p) % q
    k_inv = pow(k, -1, q)
    s = (k_inv * (H_m + x * r)) % q
    return (r, s)

sig1 = sign(k=5)
sig2 = sign(k=9)

print(f"Message Digest: {H_m}")
print(f"Signature 1 (k=5): r={sig1[0]}, s={sig1[1]}")
print(f"Signature 2 (k=9): r={sig2[0]}, s={sig2[1]}")
print(f"Deterministic RSA Equivalent: Identical across repeated calls.")