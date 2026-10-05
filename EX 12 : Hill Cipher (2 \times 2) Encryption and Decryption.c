// EXPERIMENT 12
#include <stdio.h>
#include <string.h>

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1) return x;
    return -1;
}

int main() {
    int key[2][2] = {{9, 4}, {5, 7}};
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
    if (det < 0) det += 26;
    int invDet = modInverse(det, 26);

    int invKey[2][2];
    invKey[0][0] = ( key[1][1] * invDet) % 26;
    invKey[0][1] = (-key[0][1] * invDet % 26 + 26) % 26;
    invKey[1][0] = (-key[1][0] * invDet % 26 + 26) % 26;
    invKey[1][1] = ( key[0][0] * invDet) % 26;

    char pt[] = "MEETME";
    int ct[6], dt[6];

    for (int i = 0; i < 6; i += 2) {
        int p1 = pt[i] - 'A', p2 = pt[i+1] - 'A';
        ct[i]   = (key[0][0]*p1 + key[0][1]*p2) % 26;
        ct[i+1] = (key[1][0]*p1 + key[1][1]*p2) % 26;
    }

    printf("Ciphertext: ");
    for (int i = 0; i < 6; i++) printf("%c", ct[i] + 'A');
    printf("\n");

    for (int i = 0; i < 6; i += 2) {
        dt[i]   = (invKey[0][0]*ct[i] + invKey[0][1]*ct[i+1]) % 26;
        dt[i+1] = (invKey[1][0]*ct[i] + invKey[1][1]*ct[i+1]) % 26;
    }

    printf("Decrypted:  ");
    for (int i = 0; i < 6; i++) printf("%c", dt[i] + 'A');
    printf("\n");
    return 0;
}
