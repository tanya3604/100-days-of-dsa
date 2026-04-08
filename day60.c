#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree
Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    Node* root = createNode(arr[0]);
    Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        Node* curr = queue[front++];

        if (i < n) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
            i++;
        }

        if (i < n) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
            i++;
        }
    }

    return root;
}

// Count nodes
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check CBT
int isCBT(Node* root, int index, int total) {
    if (!root) return 1;

    if (index >= total)
        return 0;

    return isCBT(root->left, 2 * index + 1, total) &&
           isCBT(root->right, 2 * index + 2, total);
}

// Check Min-Heap property
int isMinHeap(Node* root) {
    if (!root->left && !root->right)
        return 1;

    if (!root->right) {
        return (root->data <= root->left->data);
    }

    return (root->data <= root->left->data &&
            root->data <= root->right->data &&
            isMinHeap(root->left) &&
            isMinHeap(root->right));
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    int total = countNodes(root);

    if (isCBT(root, 0, total) && isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}