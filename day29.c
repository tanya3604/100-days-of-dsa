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

// Rotate right by k places
struct Node* rotateRight(struct Node* head, int k) {
    
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    
    int n = getLength(head);
    k = k % n;   // Handle k > n
    
    if (k == 0)
        return head;
    
    struct Node* temp = head;
    
    // Go to last node
    while (temp->next != NULL)
        temp = temp->next;
    
    // Make it circular
    temp->next = head;
    
    // Move to (n-k)th node
    int steps = n - k;
    struct Node* newTail = head;
    
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;
    
    // New head
    struct Node* newHead = newTail->next;
    
    // Break circle
    newTail->next = NULL;
    
    return newHead;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    
    int n, value, k;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    scanf("%d", &k);
    
    head = rotateRight(head, k);
    
    printList(head);
    
    return 0;
}