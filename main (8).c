// EXPERIMENT0EXPERIMENT 08
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char keyword[50];
    char cipherAlphabet[27];
    int used[26] = {0};
    int idx = 0;

    printf("Enter keyword: ");
    scanf("%s", keyword);

    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (!used[ch - 'A']) {
            cipherAlphabet[idx++] = ch;
            used[ch - 'A'] = 1;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            cipherAlphabet[idx++] = ch;
            used[ch - 'A'] = 1;
        }
    }
    cipherAlphabet[26] = '\0';

    printf("Plain : abcdefghijklmnopqrstuvwxyz\n");
    printf("Cipher: %s\n", cipherAlphabet);
    return 0;
}
