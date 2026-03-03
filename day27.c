#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Get length of list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection point
int findIntersection(struct Node* head1, struct Node* head2) {
    
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    int diff = abs(len1 - len2);
    
    // Move pointer of longer list ahead
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }
    
    // Traverse together
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1->data;
        
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return -1; // No intersection
}

int main() {
    
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *tail1 = NULL, *tail2 = NULL;
    
    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        
        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }
    
    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        
        if (head2 == NULL) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }
    
    int result = findIntersection(head1, head2);
    
    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);
    
    return 0;
}