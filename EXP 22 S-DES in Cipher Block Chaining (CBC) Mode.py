from Crypto.Cipher import DES3
from Crypto.Util.Padding import pad, unpad

key = b'123456789012345678901234'
iv = b'12345678'

text = input("Enter plaintext: ").encode()

cipher = DES3.new(key, DES3.MODE_CBC, iv)
encrypted = cipher.encrypt(pad(text, 8))
print("Encrypted:", encrypted.hex())

cipher = DES3.new(key, DES3.MODE_CBC, iv)
decrypted = unpad(cipher.decrypt(encrypted), 8)
print("Decrypted:", decrypted.decode())