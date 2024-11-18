#include <stdio.h>
#include<stdlib.h>
#define MAX 10

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;  // For undirected graph
}

void displayMatrix(int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// DFS Function
void DFS(int vertex, int vertices) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }
}

// BFS Function
void BFS(int start, int vertices) {
    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int vertices, edges, u, v, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the adjacency matrix and visited array
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input edges
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    displayMatrix(vertices);

    // DFS Traversal
    printf("\nDFS Traversal starting from vertex 0: ");
    DFS(0, vertices);

    // Reset visited array for BFS
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    // BFS Traversal
    printf("\nBFS Traversal starting from vertex 0: ");
    BFS(0, vertices);

    return 0;
}
