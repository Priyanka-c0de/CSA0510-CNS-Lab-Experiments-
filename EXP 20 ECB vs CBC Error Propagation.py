from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

key = b'1234567890123456'
cipher = AES.new(key, AES.MODE_ECB)

text = input("Enter plaintext: ").encode()
encrypted = cipher.encrypt(pad(text, 16))

print("Ciphertext:", encrypted.hex())