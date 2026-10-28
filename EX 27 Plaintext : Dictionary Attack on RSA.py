n, e = 3599, 31

# Encrypting characters individually
message = "ATTACK"
ciphertext = [pow(ord(c) - ord('A'), e, n) for c in message]
print(f"Ciphertext blocks: {ciphertext}")

# Attacker's dictionary attack
codebook = {pow(m, e, n): chr(m + ord('A')) for m in range(26)}
recovered = "".join(codebook[c] for c in ciphertext)
print(f"Decrypted without private key: {recovered}")