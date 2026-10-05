// EXPERIMENT 04 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char pt[100], key[50], ct[100], dt[100];
    printf("Enter plaintext: ");
    scanf("%s", pt);
    printf("Enter key: ");
    scanf("%s", key);

    int ptLen = strlen(pt), keyLen = strlen(key);
    for (int i = 0; i < ptLen; i++) {
        char p = toupper(pt[i]) - 'A';
        char k = toupper(key[i % keyLen]) - 'A';
        ct[i] = ((p + k) % 26) + 'A';
    }
    ct[ptLen] = '\0';

    for (int i = 0; i < ptLen; i++) {
        char c = ct[i] - 'A';
        char k = toupper(key[i % keyLen]) - 'A';
        dt[i] = ((c - k + 26) % 26) + 'A';
    }
    dt[ptLen] = '\0';

    printf("Ciphertext: %s\n", ct);
    printf("Decrypted text: %s\n", dt);
    return 0;
}
