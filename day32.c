#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    stack[++top] = value;
}

// Pop function
void pop() {
    if (top != -1) {
        top--;
    }
}

int main() {
    int n, m, i;

    // Input number of elements
    scanf("%d", &n);

    // Input elements and push
    for(i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform pop operations
    for(i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack (top to bottom)
    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}