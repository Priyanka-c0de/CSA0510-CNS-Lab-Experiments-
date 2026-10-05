//EXPERIMENT  13
#include <stdio.h>

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1) return x;
    return -1;
}

int main() {
    int P[2][2] = {{4, 11}, {11, 14}}; // Plain: "EL", "LO"
    int C[2][2] = {{14, 21}, {9, 10}}; // Corresponding cipher

    int det = (P[0][0]*P[1][1] - P[0][1]*P[1][0]) % 26;
    if (det < 0) det += 26;
    int invDet = modInverse(det, 26);

    int P_inv[2][2];
    P_inv[0][0] = (P[1][1] * invDet) % 26;
    P_inv[0][1] = (-P[0][1] * invDet % 26 + 26) % 26;
    P_inv[1][0] = (-P[1][0] * invDet % 26 + 26) % 26;
    P_inv[1][1] = (P[0][0] * invDet) % 26;

    int K[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            K[i][j] = (P_inv[i][0] * C[0][j] + P_inv[i][1] * C[1][j]) % 26;
        }
    }

    printf("Recovered Key Matrix:\n");
    printf("[%d  %d]\n[%d  %d]\n", K[0][0], K[0][1], K[1][0], K[1][1]);
    return 0;
}
