#include <stdio.h>
#include <string.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Size
int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

// Push front
void push_front(int x) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }
    if (empty()) {
        front = rear = 0;
    } else {
        front--;
    }
    dq[front] = x;
}

// Push back
void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if (empty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    dq[rear] = x;
}

// Pop front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[front]);
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

// Pop back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[rear]);
    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

// Front element
void get_front() {
    if (empty()) printf("-1\n");
    else printf("%d\n", dq[front]);
}

// Back element
void get_back() {
    if (empty()) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

// Display
void display() {
    if (empty()) return;
    for (int i = front; i <= rear; i++) {
        printf("%d ", dq[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            int x; scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(op, "push_back") == 0) {
            int x; scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(op, "front") == 0) {
            get_front();
        }
        else if (strcmp(op, "back") == 0) {
            get_back();
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(op, "display") == 0) {
            display();
        }
    }

    return 0;
}