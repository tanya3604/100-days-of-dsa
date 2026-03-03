#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

// Display operation (top to bottom)
void display() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    
    int n, type, value;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        
        scanf("%d", &type);
        
        if (type == 1) {          // Push
            scanf("%d", &value);
            push(value);
        }
        else if (type == 2) {     // Pop
            pop();
        }
        else if (type == 3) {     // Display
            display();
        }
    }
    
    return 0;
}