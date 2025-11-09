#include <stdio.h>

int knapsack(int W, int wt[], int val[], int n, int selected[]) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = (val[i - 1] + dp[i - 1][w - wt[i - 1]] > dp[i - 1][w])
                               ? (val[i - 1] + dp[i - 1][w - wt[i - 1]])
                               : dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    int res = dp[n][W];
    int w = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w])
            selected[i - 1] = 0;
        else {
            selected[i - 1] = 1;
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }
    return dp[n][W];
}

int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n], selected[n];
    printf("Enter values of items: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter weights of items: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    for (int i = 0; i < n; i++)
        selected[i] = 0;

    int W;
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int maxVal = knapsack(W, wt, val, n, selected);

    printf("Maximum value in knapsack = %d\n", maxVal);
    printf("Selected items array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", selected[i]);
    printf("\n");
    return 0;
}
