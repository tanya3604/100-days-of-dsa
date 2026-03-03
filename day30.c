#include <stdio.h>
#include <stdlib.h>

// Structure for Polynomial Node
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert in decreasing order of exponent
struct Node* insertSorted(struct Node* head, int c, int e) {
    
    struct Node* newNode = createNode(c, e);
    
    // If list empty or new exponent is greater than head
    if (head == NULL || e > head->exp) {
        newNode->next = head;
        return newNode;
    }
    
    struct Node* temp = head;
    
    while (temp->next != NULL && temp->next->exp > e) {
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    
    return head;
}

// Print polynomial
void printPolynomial(struct Node* head) {
    
    struct Node* temp = head;
    
    while (temp != NULL) {
        
        if (temp->exp == 0)
            printf("%d", temp->coeff);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);
        
        if (temp->next != NULL)
            printf(" + ");
        
        temp = temp->next;
    }
}

int main() {
    
    int n, c, e;
    struct Node* head = NULL;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        head = insertSorted(head, c, e);
    }
    
    printPolynomial(head);
    
    return 0;
}