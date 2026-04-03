#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert
void insert(int x) {
    pq[size++] = x;
}

// Find index of minimum element
int findMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete (remove min)
int deleteMin() {
    if (size == 0) return -1;

    int minIndex = findMinIndex();
    int minValue = pq[minIndex];

    // Shift elements
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
    return minValue;
}

// Peek (get min)
int peek() {
    if (size == 0) return -1;

    int minIndex = findMinIndex();
    return pq[minIndex];
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i') { // insert
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') { // delete
            printf("%d\n", deleteMin());
        }
        else if (op[0] == 'p') { // peek
            printf("%d\n", peek());
        }
    }

    return 0;
}