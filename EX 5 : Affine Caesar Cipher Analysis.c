// EXPERIMENT 05
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int modInverse(int a) {
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1) return x;
    }
    return -1;
}

int main() {
    int a, b;
    char text[100];
    printf("Affine Cipher: C = (a*p + b) mod 26\n");
    printf("Values of 'a' NOT allowed: ");
    for (int i = 0; i < 26; i++) {
        if (gcd(i, 26) != 1) printf("%d ", i);
    }
    printf("\nCondition on b: Any integer in range [0, 25].\n\n");

    printf("Enter 'a' and 'b': ");
    scanf("%d %d", &a, &b);
    if (gcd(a, 26) != 1) {
        printf("Invalid 'a'! Must be coprime with 26.\n");
        return 0;
    }

    printf("Enter plaintext: ");
    scanf("%s", text);
    int a_inv = modInverse(a);

    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = (((a * (toupper(text[i]) - 'A')) + b) % 26) + 'A';
    }
    printf("Encrypted: %s\n", text);

    for (int i = 0; text[i] != '\0'; i++) {
        int c = text[i] - 'A';
        text[i] = ((a_inv * (c - b + 26)) % 26) + 'A';
    }
    printf("Decrypted: %s\n", text);
    return 0;
}
