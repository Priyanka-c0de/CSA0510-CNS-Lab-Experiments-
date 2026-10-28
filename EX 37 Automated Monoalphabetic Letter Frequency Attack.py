from collections import Counter

ct = "GWCUG GUCK QWERT"
counts = Counter(c for c in ct if c.isalpha())
ordered = [k for k, _ in counts.most_common()]
ref_freq = "ETAOINSHRDLCUMWFGYPBVKJXQZ"

print("Top candidate plaintexts:")
for shift in range(10):
    mapping = {}
    for i, c in enumerate(ordered):
        mapping[c] = ref_freq[(i + shift) % len(ref_freq)]
    cand = "".join(mapping.get(c, c) if c.isalpha() else c for c in ct)
    print(f"{shift + 1}. {cand}")