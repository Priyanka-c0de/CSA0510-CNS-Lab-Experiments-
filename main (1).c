//EXPERIMENT 01
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarEncrypt(char text[], int k) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i]))
            text[i] = ((text[i] - 'A' + k) % 26) + 'A';
        else if (islower(text[i]))
            text[i] = ((text[i] - 'a' + k) % 26) + 'a';
    }
}

void caesarDecrypt(char text[], int k) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i]))
            text[i] = ((text[i] - 'A' - k + 26) % 26) + 'A';
        else if (islower(text[i]))
            text[i] = ((text[i] - 'a' - k + 26) % 26) + 'a';
    }
}

int main() {
    char str[100];
    int k;
    printf("Enter plaintext: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Enter shift key (1-25): ");
    scanf("%d", &k);

    caesarEncrypt(str, k);
    printf("Ciphertext: %s\n", str);
    caesarDecrypt(str, k);
    printf("Decrypted text: %s\n", str);
    return 0;
}
