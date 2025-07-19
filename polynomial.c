#include <stdio.h>

int main() {
    int a[10], b[10], sum[10], deg, i;

    printf("Enter the degree of the polynomials: ");
    scanf("%d", &deg);

    printf("Enter coefficients of first polynomial:\n");
    for(i = 0; i <= deg; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter coefficients of second polynomial:\n");
    for(i = 0; i <= deg; i++) {
        scanf("%d", &b[i]);
    }

    // Adding the polynomials
    for(i = 0; i <= deg; i++) {
        sum[i] = a[i] + b[i];
    }

    // Displaying the result
    printf("Sum of the polynomials:\n");
    for(i = deg; i >= 0; i--) {
        if(sum[i] != 0) {
            printf("%dx^%d", sum[i], i);
            if(i != 0)
                printf(" + ");
        }
    }

    printf("\n");
    return 0;
}
