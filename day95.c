#include <stdio.h>
#include <stdlib.h>

// Node for linked list bucket
struct Node {
    float data;
    struct Node* next;
};

// Insert in sorted order (Insertion Sort in bucket)
void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* curr = *head;
        while (curr->next != NULL && curr->next->data < value) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

// Bucket Sort
void bucketSort(float arr[], int n) {
    // Create buckets
    struct Node* buckets[n];
    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];  // bucket index
        insertSorted(&buckets[index], arr[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->data;
            curr = curr->next;
        }
    }
}

// Print array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    printArray(arr, n);
    return 0;
}