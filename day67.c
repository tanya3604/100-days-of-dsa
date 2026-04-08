#include <stdio.h>

#define MAX 100

int visited[MAX], stack[MAX], top = -1;

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int node, int n, int adj[MAX][MAX]) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, n, adj);
        }
    }

    push(node); // push after visiting all neighbors
}

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Call DFS for all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, adj);
        }
    }

    // Print topological order
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}