//EXPERIMENT  15
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char p1[] = "sendmoremoney";
    int k1[] = {9, 0, 17, 23, 15, 21, 14, 11, 11, 2, 8, 9, 7};
    int len = strlen(p1);
    int c[len];

    printf("a. Encrypting:\nCiphertext: ");
    for (int i = 0; i < len; i++) {
        c[i] = ((p1[i] - 'a') + k1[i]) % 26;
        printf("%c", c[i] + 'A');
    }
    printf("\n\nb. Deduced key stream for 'cashnotneeded':\n");

    char p2[] = "cashnotneeded";
    printf("Keystream: ");
    for (int i = 0; i < len; i++) {
        int k2 = (c[i] - (p2[i] - 'a') + 26) % 26;
        printf("%d ", k2);
    }
    printf("\n");
    return 0;
}
