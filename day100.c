#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int val;
    int index;
};

// Merge function
void merge(struct Pair arr[], int left, int mid, int right, int count[]) {
    int n = right - left + 1;
    struct Pair temp[n];

    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    while(i <= mid && j <= right) {
        if(arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;  // smaller element found
        } else {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while(i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while(j <= right) {
        temp[k++] = arr[j++];
    }

    for(i = 0; i < n; i++) {
        arr[left + i] = temp[i];
    }
}

// Merge Sort
void mergeSort(struct Pair arr[], int left, int right, int count[]) {
    if(left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);

    merge(arr, left, mid, right, count);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Pair arr[n];
    int count[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    for(int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}