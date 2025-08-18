#include <stdio.h>
#include <math.h>

int main() {
    int n, x;
    int sum1 = 1, sum2;
    printf("Enter value of x and n: ");
    scanf("%d %d", &x, &n);

    int term = 1;
    for (int i = 1; i <= n; i++) {
        term *= x;
        sum1 += term;
    }

    if (x == 1)
        sum2 = n + 1;
    else
        sum2 = (pow(x, n + 1) - 1) / (x - 1);

    printf("Sum using loop     = %d\n", sum1);
    printf("Sum using formula  = %d\n", sum2);

    return 0;
}
