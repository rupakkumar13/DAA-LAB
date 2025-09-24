#include <stdio.h>

void sortItems(int v[], int w[], double u[], int n) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(u[i] < u[j]) {
                double tempU = u[i];
                u[i] = u[j];
                u[j] = tempU;

                int tempW = w[i];
                w[i] = w[j];
                w[j] = tempW;

                int tempV = v[i];
                v[i] = v[j];
                v[j] = tempV;
            }
        }
    }
}

int main() {
    int n, sackcap;
    printf("Enter the sack capacity: ");
    scanf("%d", &sackcap);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int w[n], v[n];
    printf("Enter weights: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter values: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    double u[n];
    for(int i=0; i<n; i++) {
        u[i] = (double)v[i] / w[i];
    }

    sortItems(v, w, u, n);

    double currentWt = 0.0, totalVal = 0.0;

    for(int i=0; i<n; i++) {
        if(currentWt + w[i] <= sackcap) {
            currentWt += w[i];
            totalVal += v[i];
        } else {
            int remain = sackcap - currentWt;
            totalVal += v[i] * ((double)remain / w[i]);
            break;
        }
    }

    printf("Maximum value in knapsack = %.2lf\n", totalVal);

    return 0;
}
