#include <stdio.h>

int main() {
    int n, i, key;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Element to search
    scanf("%d", &key);

    int low = 0, high = n - 1, mid;

    // Binary Search
    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            printf("Found at index %d", mid);
            return 0;
        }
        else if(key < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    printf("Not Found");

    return 0;
}