// EXPERIMENT0EXPERIMENT06
#include <stdio.h>

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1) return x;
    return -1;
}

int main() {
    int p1 = 4, c1 = 1;   // E -> B
    int p2 = 19, c2 = 20; // T -> U

    int diff_p = (p2 - p1 + 26) % 26;
    int diff_c = (c2 - c1 + 26) % 26;

    int inv = modInverse(diff_p, 26);
    int a = (diff_c * inv) % 26;
    int b = (c1 - a * p1) % 26;
    if (b < 0) b += 26;

    printf("Deductions:\n");
    printf("Key a = %d\n", a);
    printf("Key b = %d\n", b);

    int a_inv = modInverse(a, 26);
    char ct[] = "BUBU";
    printf("Decrypting ciphertext %s: ", ct);
    for (int i = 0; ct[i] != '\0'; i++) {
        int p = (a_inv * ((ct[i] - 'A') - b + 26)) % 26;
        printf("%c", p + 'A');
    }
    printf("\n");
    return 0;
}
