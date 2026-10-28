import random

plaintext = "CRYPTOGRAPHY"
# Generate key stream between 0 and 25 matching plaintext length
key_stream = [random.randint(0, 25) for _ in plaintext]

ciphertext = "".join(
    chr(((ord(p) - ord('A') + k) % 26) + ord('A'))
    for p, k in zip(plaintext, key_stream)
)

decrypted = "".join(
    chr(((ord(c) - ord('A') - k + 26) % 26) + ord('A'))
    for c, k in zip(ciphertext, key_stream)
)

print(f"Plaintext : {plaintext}")
print(f"Keystream : {key_stream}")
print(f"Ciphertext: {ciphertext}")
print(f"Decrypted : {decrypted}")