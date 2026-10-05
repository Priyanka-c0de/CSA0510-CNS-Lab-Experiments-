//EXPERIMENT 02
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char key[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";

void monoEncrypt(char text[], char res[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) res[i] = key[text[i] - 'A'];
        else if (islower(text[i])) res[i] = tolower(key[text[i] - 'a']);
        else res[i] = text[i];
    }
    res[strlen(text)] = '\0';
}

void monoDecrypt(char text[], char res[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char target = toupper(text[i]);
            for (int j = 0; j < 26; j++) {
                if (key[j] == target) {
                    res[i] = isupper(text[i]) ? ('A' + j) : ('a' + j);
                    break;
                }
            }
        } else {
            res[i] = text[i];
        }
    }
    res[strlen(text)] = '\0';
}

int main() {
    char str[100], enc[100], dec[100];
    printf("Enter plaintext: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    monoEncrypt(str, enc);
    printf("Ciphertext: %s\n", enc);
    monoDecrypt(enc, dec);
    printf("Decrypted text: %s\n", dec);
    return 0;
}
