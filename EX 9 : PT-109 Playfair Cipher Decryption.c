//EXPERIMENT 09
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5] = {
    {'R', 'O', 'Y', 'A', 'L'},
    {'N', 'E', 'W', 'Z', 'D'},
    {'B', 'C', 'F', 'G', 'H'},
    {'I', 'K', 'M', 'P', 'Q'},
    {'S', 'T', 'U', 'V', 'X'}
};

void findPos(char c, int *r, int *col) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == c) { *r = i; *col = j; return; }
}

int main() {
    char ct[] = "KXJEYUREBEZWEHEWRYTU";
    printf("Ciphertext: %s\nDecrypted: ", ct);

    for (int i = 0; i < strlen(ct); i += 2) {
        int r1, c1, r2, c2;
        findPos(ct[i], &r1, &c1);
        findPos(ct[i+1], &r2, &c2);
        if (r1 == r2)
            printf("%c%c", matrix[r1][(c1 + 4) % 5], matrix[r2][(c2 + 4) % 5]);
        else if (c1 == c2)
            printf("%c%c", matrix[(r1 + 4) % 5][c1], matrix[(r2 + 4) % 5][c2]);
        else
            printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
    }
    printf("\n");
    return 0;
}
