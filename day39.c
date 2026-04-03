#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify Down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert
void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// Extract Min
int extractMin() {
    if (size == 0) return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
    return min;
}

// Peek
int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char op[20];
        scanf("%s", op);

        if (op[0] == 'i') {  // insert
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'e') {  // extractMin
            printf("%d\n", extractMin());
        }
        else if (op[0] == 'p') {  // peek
            printf("%d\n", peek());
        }
    }

    return 0;
}