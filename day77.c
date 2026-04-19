#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int* visited, int** graph, int* colSize) {
    visited[node] = 1;

    for (int i = 0; i < colSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph, colSize);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** edges = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        edges[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    // degree count
    int* degree = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i < m; i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    // adjacency list
    int** graph = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 1; i <= n; i++) {
        graph[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    int* idx = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u][idx[u]++] = v;
        graph[v][idx[v]++] = u;
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));

    // start DFS from node 1
    dfs(1, visited, graph, degree);

    // check all nodes visited?
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}