q, a = 353, 3  # Public parameters
xA_secret = 45 # Alice's secret

# Exchange: Alice sends YA = xA^a mod q
YA = pow(xA_secret, a, q)

# Eve computes modular inverse of a mod (q - 1)
phi = q - 1
a_inv = pow(a, -1, phi)
recovered_xA = pow(YA, a_inv, q)

print(f"Public q={q}, a={a}")
print(f"Alice's transmitted value: {YA}")
print(f"Eve recovered secret xA: {recovered_xA}")