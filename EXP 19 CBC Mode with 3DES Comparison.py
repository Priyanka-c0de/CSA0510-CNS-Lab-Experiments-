from Crypto.Cipher import DES3
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad

key = DES3.adjust_key_parity(get_random_bytes(24))
iv = get_random_bytes(8)

cipher = DES3.new(key, DES3.MODE_CBC, iv)

text = input("Enter plaintext: ").encode()
encrypted = cipher.encrypt(pad(text, 8))

print("IV:", iv.hex())
print("Ciphertext:", encrypted.hex())