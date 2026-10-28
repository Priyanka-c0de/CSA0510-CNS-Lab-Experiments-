import math

def check_affine(a, b):
    outputs = [((a * p + b) % 26) for p in range(26)]
    is_one_to_one = len(set(outputs)) == 26
    return is_one_to_one, outputs

for a in [2, 7]:
    valid, outputs = check_affine(a, b=3)
    gcd_val = math.gcd(a, 26)
    print(f"a={a}, b=3 | gcd(a,26)={gcd_val} | One-to-One: {valid}")
    if not valid:
        print(f"  Collision: E(0)={outputs[0]} and E(13)={outputs[13]}")
    else:
        a_inv = pow(a, -1, 26)
        print(f"  Valid key pair. Decryption inverse a^(-1) = {a_inv}")