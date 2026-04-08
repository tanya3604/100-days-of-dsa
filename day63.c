#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Create node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function
void dfs(int v, Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // adjacency list
    Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int m;
    scanf("%d", &m);

    int u, v;

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // directed graph
        Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Uncomment for undirected graph
        /*
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
        */
    }

    int s;
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(s, adj, visited);

    return 0;
}