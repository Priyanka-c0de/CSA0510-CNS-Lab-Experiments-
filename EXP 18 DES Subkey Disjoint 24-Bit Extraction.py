key = input("Enter 64-bit key in binary: ")

key = key[1::2]  # Remove parity bits (8 bits)
C = key[:28]
D = key[28:56]

shifts = [1, 1, 2, 2, 2, 2, 2, 2,
          1, 2, 2, 2, 2, 2, 2, 1]

for i, shift in enumerate(shifts, 1):
    C = C[shift:] + C[:shift]
    D = D[shift:] + D[:shift]
    subkey = C + D
    print("K" + str(i) + ":", subkey)