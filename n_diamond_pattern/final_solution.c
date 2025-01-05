#include <stdio.h>

int main() {
    int n, i, j, space, k;

    printf("Enter an odd integer: ");
    scanf("%d", &n);

    // Validate input
    if (n % 2 == 0) {
        printf("Invalid input, please enter an odd integer.\n");
        return 1;
    }

    space = n / 2;

    // Upper half of the diamond
    for (i = 1; i <= n / 2 + 1; i++) {
        for (j = 1; j <= space; j++) {
            printf(" ");
        }
        space--;

        for (k = 1; k <= 2 * i - 1; k++) {
            if (k <= i) {
                printf("%d", k);
            } else {
                printf("%d", 2 * i - k);
            }
        }
        printf("\n");
    }

    space = 1;

    // Lower half of the diamond
    for (i = n / 2; i >= 1; i--) {
        for (j = 1; j <= space; j++) {
            printf(" ");
        }
        space++;

        for (k = 1; k <= 2 * i - 1; k++) {
            if (k <= i) {
                printf("%d", k);
            } else {
                printf("%d", 2 * i - k);
            }
        }
        printf("\n");
    }

    return 0;
}