#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    // Since constraints small assume range
    int hash[1000];
    for (int i = 0; i < 1000; i++)
        hash[i] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // case 1: sum = 0
        if (sum == 0) {
            max_len = i + 1;
        }

        // case 2: sum seen before
        if (hash[sum + 500] != -1) {
            int len = i - hash[sum + 500];
            if (len > max_len)
                max_len = len;
        } else {
            hash[sum + 500] = i;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of longest subarray with sum 0: %d", maxLen(arr, n));

    return 0;
}