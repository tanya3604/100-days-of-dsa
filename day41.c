#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    // Add at the end
    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", front->data);

    front = front->next;

    // If queue becomes empty
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

int main() {
    int N;
    scanf("%d", &N);

    char operation[20];
    int value;

    for (int i = 0; i < N; i++) {
        scanf("%s", operation);

        if (operation[0] == 'e') {  // enqueue
            scanf("%d", &value);
            enqueue(value);
        } else if (operation[0] == 'd') {  // dequeue
            dequeue();
        }
    }

    return 0;
}