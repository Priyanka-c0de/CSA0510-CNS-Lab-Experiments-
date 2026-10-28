def pad(data, block_size=8):
    pad_len = block_size - (len(data) % block_size)
    if pad_len == 0:
        pad_len = block_size
    # 0x80 corresponds to binary '10000000'
    return data + bytes([0x80] + [0x00] * (pad_len - 1))

def unpad(data):
    for i in range(len(data) - 1, -1, -1):
        if data[i] == 0x80:
            return data[:i]
        elif data[i] != 0x00:
            raise ValueError("Invalid padding")
    return data

data_partial = b"HELLO"
padded_partial = pad(data_partial, 8)
print(f"Partial input '{data_partial.decode()}': {padded_partial.hex()} -> Unpad: {unpad(padded_partial).decode()}")

data_exact = b"12345678"  # Exactly 8 bytes
padded_exact = pad(data_exact, 8)
print(f"Exact input '{data_exact.decode()}': {padded_exact.hex()} (Appended full block) -> Unpad: {unpad(padded_exact).decode()}")