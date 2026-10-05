// EXPERIMENT 07
#include <stdio.h>
#include <string.h>

char decryptChar(char c) {
    switch (c) {
        case '5': return 'e';
        case '3': return 'g';
        case '#': return 'o';
        case '+': return 'd';
        case '4': return 't';
        case '8': return 'h';
        case ';': return 'e';
        case '*': return 'n';
        case ')': return 's';
        case '(': return 'r';
        default: return c;
    }
}

int main() {
    char ciphertext[] = "53##+305))6*;4826)4";
    printf("Ciphertext: %s\nPlaintext: ", ciphertext);
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        putchar(decryptChar(ciphertext[i]));
    }
    printf("\n");
    return 0;
}
