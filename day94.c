#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    // Step 1: Find max
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create count array
    int *count = (int *)calloc(max + 1, sizeof(int));

    // Step 3: Store frequencies
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 4: Prefix sum
    for(int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Build output array (stable)
    int output[n];
    for(int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 6: Copy back
    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    printArray(arr, n);
    return 0;
}