        #include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue Node (for BFS)
struct QNode {
    struct Node* node;
    int hd;
    struct QNode* next;
};

// Create new tree node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Create queue node
struct QNode* newQNode(struct Node* node, int hd) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;
    return temp;
}

// Enqueue
void enqueue(struct QNode** front, struct QNode** rear, struct Node* node, int hd) {
    struct QNode* temp = newQNode(node, hd);
    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
}

// Dequeue
struct QNode* dequeue(struct QNode** front, struct QNode** rear) {
    if (*front == NULL) return NULL;
    struct QNode* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];
            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct QNode *front = NULL, *rear = NULL;

    // Map using array (offset for negative HD)
    int offset = 100;
    int map[200][100];   // store values
    int count[200] = {0};

    enqueue(&front, &rear, root, 0);

    while (front != NULL) {
        struct QNode* temp = dequeue(&front, &rear);
        struct Node* node = temp->node;
        int hd = temp->hd;

        int index = hd + offset;
        map[index][count[index]++] = node->data;

        if (node->left)
            enqueue(&front, &rear, node->left, hd - 1);
        if (node->right)
            enqueue(&front, &rear, node->right, hd + 1);

        free(temp);
    }

    // Print from leftmost to rightmost
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}