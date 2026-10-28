def derive_cmac_subkeys(L, block_bits):
    mask = (1 << block_bits) - 1
    Rb = 0x1B if block_bits == 64 else 0x87
    
    # Derive K1
    msb_L = (L >> (block_bits - 1)) & 1
    K1 = ((L << 1) & mask) ^ (Rb if msb_L else 0)
    
    # Derive K2
    msb_K1 = (K1 >> (block_bits - 1)) & 1
    K2 = ((K1 << 1) & mask) ^ (Rb if msb_K1 else 0)
    
    return hex(K1), hex(K2)

L_128 = 0x2b7e151628aed2a6abf7158809cf4f3c
k1, k2 = derive_cmac_subkeys(L_128, 128)
print(f"Block Size: 128-bit (Rb = 0x87)")
print(f"K1: {k1}")
print(f"K2: {k2}")