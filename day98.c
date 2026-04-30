#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting by start time
int compare(const void *a, const void *b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

void mergeIntervals(int arr[][2], int n) {
    // Step 1: Sort intervals
    qsort(arr, n, sizeof(arr[0]), compare);

    // Result array
    int res[n][2];
    int idx = 0;

    res[0][0] = arr[0][0];
    res[0][1] = arr[0][1];

    for(int i = 1; i < n; i++) {
        // If overlap
        if(arr[i][0] <= res[idx][1]) {
            if(arr[i][1] > res[idx][1])
                res[idx][1] = arr[i][1];
        } else {
            idx++;
            res[idx][0] = arr[i][0];
            res[idx][1] = arr[i][1];
        }
    }

    // Print result
    for(int i = 0; i <= idx; i++) {
        printf("%d %d\n", res[i][0], res[i][1]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n][2];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    mergeIntervals(arr, n);
    return 0;
}