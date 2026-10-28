def feistel_round(left, right, subkey):
    # Round function F: (R ^ K) combined and permuted
    f_res = (right ^ subkey) * 13 % 16
    return right, left ^ f_res

# 8-bit block toy Feistel simulation
def des_toy(block, subkeys):
    left, right = (block >> 4) & 0xF, block & 0xF
    for k in subkeys:
        left, right = feistel_round(left, right, k)
    return (right << 4) | left  # Final swap

keys = [0x5, 0xA, 0x3, 0xF]
pt = 0x4B
ct = des_toy(pt, keys)
dt = des_toy(ct, list(reversed(keys)))

print(f"Plaintext : {hex(pt)}")
print(f"Ciphertext: {hex(ct)}")
print(f"Decrypted : {hex(dt)}")