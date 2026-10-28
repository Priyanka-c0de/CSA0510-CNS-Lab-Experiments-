from Crypto.Cipher import AES

key = b'1234567890123456'
nonce = b'12345678'

text = input("Enter plaintext: ").encode()

cipher = AES.new(key, AES.MODE_CTR, nonce=nonce)
encrypted = cipher.encrypt(text)
print("Encrypted:", encrypted.hex())

cipher = AES.new(key, AES.MODE_CTR, nonce=nonce)
decrypted = cipher.decrypt(encrypted)
print("Decrypted:", decrypted.decode())