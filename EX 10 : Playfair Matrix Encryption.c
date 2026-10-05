// EXPERIMENT 10
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char table[5][5] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

void findPos(char c, int *r, int *col) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (table[i][j] == c) { *r = i; *col = j; return; }
}

int main() {
    char str[] = "MUSTSEEYOUOVERCADOGANWEST";
    char formatted[100];
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) formatted[len++] = toupper(str[i]);
    }
    
    printf("Encrypted: ");
    for (int i = 0; i < len; i += 2) {
        char a = formatted[i];
        char b = (i + 1 < len) ? formatted[i+1] : 'X';
        if (a == b) { b = 'X'; i--; }
        int r1, c1, r2, c2;
        findPos(a, &r1, &c1);
        findPos(b, &r2, &c2);
        if (r1 == r2)
            printf("%c%c", table[r1][(c1 + 1) % 5], table[r2][(c2 + 1) % 5]);
        else if (c1 == c2)
            printf("%c%c", table[(r1 + 1) % 5][c1], table[(r2 + 1) % 5][c2]);
        else
            printf("%c%c", table[r1][c2], table[r2][c1]);
    }
    printf("\n");
    return 0;
}
