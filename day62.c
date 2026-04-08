#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    // Array of pointers (Adjacency List)
    Node* adj[n];

    // Initialize all lists as NULL
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Add edge u -> v
        Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Uncomment below for undirected graph
        /*
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
        */
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        Node* temp = adj[i];

        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}