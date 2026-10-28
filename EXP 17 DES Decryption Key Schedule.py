from Crypto.Cipher import DES

key = b'8bytekey'
ciphertext = bytes.fromhex(input("Enter ciphertext (hex): "))

des = DES.new(key, DES.MODE_ECB)
plaintext = des.decrypt(ciphertext)

print("Decrypted text:", plaintext.decode())