#include <stdio.h>

// Lower Bound: first index where arr[i] >= x
int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n;  // right = n (important)
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    
    return left;  // index of lower bound
}

// Upper Bound: first index where arr[i] > x
int upperBound(int arr[], int n, int x) {
    int left = 0, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid;
    }
    
    return left;  // index of upper bound
}

int main() {
    int n, x;

    // Input
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &x);

    // Function calls
    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    // Output
    printf("%d %d\n", lb, ub);

    return 0;
}