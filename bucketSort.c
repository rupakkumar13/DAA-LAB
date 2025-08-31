#include <stdio.h>
#include <stdlib.h>

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float *buckets[n];
    int bucketCount[n];

    for (int i = 0; i < n; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
        bucketCount[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        buckets[idx][bucketCount[idx]++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketCount[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d elements (between 0 and 1):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}
