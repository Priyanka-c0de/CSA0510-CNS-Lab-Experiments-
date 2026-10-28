from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

key = b'1234567890123456'
iv = b'abcdefghijklmnop'
text = input("Enter plaintext: ").encode()
data = pad(text, 16)

for mode in [AES.MODE_ECB, AES.MODE_CBC, AES.MODE_CFB]:
    if mode == AES.MODE_ECB:
        cipher = AES.new(key, mode)
    elif mode == AES.MODE_CBC:
        cipher = AES.new(key, mode, iv=iv)
    else:
        cipher = AES.new(key, mode, iv=iv, segment_size=128)

    print("Mode:", mode)
    print("Ciphertext:", cipher.encrypt(data).hex())