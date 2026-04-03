#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX];
int front = -1, rear = -1;

// Stack implementation
int stack[MAX];
int top = -1;

// Queue functions
void enqueue(int x) {
    if (rear == MAX - 1) return;

    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Stack functions
void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int main() {
    int N, x;
    scanf("%d", &N);

    // Input queue elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue → stack
    while (front <= rear) {
        push(dequeue());
    }

    // Step 2: Move stack → queue
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    while (front <= rear) {
        printf("%d ", dequeue());
    }

    return 0;
}