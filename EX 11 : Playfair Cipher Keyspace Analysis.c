// EXPERIMENT 11
#include <math.h>

int main() {
    double log2_25fact = 0;
    for (int i = 1; i <= 25; i++) {
        log2_25fact += log2(i);
    }
    double log2_unique = log2_25fact - log2(25);

    printf("Total possible keys (25!): ~ 2^(%.2f)\n", log2_25fact);
    printf("Effectively unique keys (24!): ~ 2^(%.2f)\n", log2_unique);
    return 0;
}
