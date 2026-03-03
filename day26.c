#include <stdio.h>
#include <stdlib.h>

// Structure for Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert at end
struct Node* insertEnd(struct Node* head, int value) {
    
    struct Node* newNode = createNode(value);
    
    // If list is empty
    if (head == NULL)
        return newNode;
    
    struct Node* temp = head;
    
    // Traverse to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
    
    return head;
}

// Function to print list in forward direction
void printList(struct Node* head) {
    struct Node* temp = head;
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    
    int n, value;
    struct Node* head = NULL;
    
    // Input number of nodes
    scanf("%d", &n);
    
    // Insert nodes
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }
    
    // Print forward traversal
    printList(head);
    
    return 0;
}