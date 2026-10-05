//EXPERIMENT  03
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char table[5][5];

void generateMatrix(char *key) {
    int map[26] = {0};
    map['J' - 'A'] = 1;
    int r = 0, c = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        if (isalpha(ch) && !map[ch - 'A']) {
            table[r][c++] = ch;
            map[ch - 'A'] = 1;
            if (c == 5) { c = 0; r++; }
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!map[ch - 'A']) {
            table[r][c++] = ch;
            map[ch - 'A'] = 1;
            if (c == 5) { c = 0; r++; }
        }
    }
}

void findPos(char ch, int *r, int *c) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (table[i][j] == ch) { *r = i; *c = j; return; }
}

void playfairEncrypt(char text[]) {
    char prep[200];
    int len = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) prep[len++] = toupper(text[i]);
    }
    char formatted[200];
    int flen = 0;
    for (int i = 0; i < len; i++) {
        formatted[flen++] = prep[i];
        if (i + 1 < len) {
            if (prep[i] == prep[i + 1]) formatted[flen++] = 'X';
            else { formatted[flen++] = prep[++i]; }
        } else {
            formatted[flen++] = 'X';
        }
    }
    printf("Encrypted: ");
    for (int i = 0; i < flen; i += 2) {
        int r1, c1, r2, c2;
        findPos(formatted[i], &r1, &c1);
        findPos(formatted[i + 1], &r2, &c2);
        if (r1 == r2) {
            printf("%c%c", table[r1][(c1 + 1) % 5], table[r2][(c2 + 1) % 5]);
        } else if (c1 == c2) {
            printf("%c%c", table[(r1 + 1) % 5][c1], table[(r2 + 1) % 5][c2]);
        } else {
            printf("%c%c", table[r1][c2], table[r2][c1]);
        }
    }
    printf("\n");
}

int main() {
    char key[50], pt[100];
    printf("Enter keyword: ");
    scanf("%s", key);
    generateMatrix(key);
    printf("Enter plaintext: ");
    scanf("%s", pt);
    playfairEncrypt(pt);
    return 0;
}
