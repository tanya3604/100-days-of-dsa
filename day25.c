#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to count occurrences
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    
    while (head != NULL) {
        if (head->data == key) {
            count++;
        }
        head = head->next;
    }
    
    return count;
}

int main() {
    int n, value, key;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    // Input number of nodes
    scanf("%d", &n);
    
    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        
        struct Node* newNode = createNode(value);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Input key
    scanf("%d", &key);
    
    // Count occurrences
    int result = countOccurrences(head, key);
    
    // Print result
    printf("%d", result);
    
    return 0;
}