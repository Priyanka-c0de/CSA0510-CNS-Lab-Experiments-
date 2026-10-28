# Simulated 16-bit block cipher
def encrypt_block(block, key):
    return (block ^ key) * 31 % 65536

key = 0xABCD
X = 0x1234
tag_T = encrypt_block(X, key)

# Adversary builds 2-block message: X || (X ^ tag_T)
block1 = X
block2 = X ^ tag_T

# CBC MAC Verification
stage1 = encrypt_block(block1, key)
stage2 = encrypt_block(block2 ^ stage1, key)

print(f"Block 1 Tag: {hex(tag_T)}")
print(f"Forged 2-Block Message MAC: {hex(stage2)}")
print(f"Attack Success: {stage2 == tag_T}")