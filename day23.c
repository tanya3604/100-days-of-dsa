#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}

struct node* insert(struct node* head, int data) {
    if (head == NULL) return create(data);
    head->next = insert(head->next, data);
    return head;
}

struct node* merge(struct node* a, struct node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

void print(struct node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    struct node *h1 = NULL, *h2 = NULL, *res;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        h1 = insert(h1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        h2 = insert(h2, x);
    }

    res = merge(h1, h2);
    print(res);

    return 0;
}
