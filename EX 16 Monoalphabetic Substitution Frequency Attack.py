from collections import Counter

cipher = input("Enter cipher text: ").upper()
freq = Counter(c for c in cipher if c.isalpha())
common = "ETAOINSHRDLCUMWFGYPBVKJXQZ"

mapping = dict(zip([c for c, n in freq.most_common()], common))

print("Possible plaintext:")
print("".join(mapping.get(c, c) for c in cipher))