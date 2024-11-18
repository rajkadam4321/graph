#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    // For undirected graph
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void displayList(int vertices) {
    printf("Adjacency List:\n");
    for (int i = 0; i < vertices; i++) {
        struct Node* temp = adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    struct Node* temp = adjList[vertex];
    while (temp) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            DFS(connectedVertex);
        }
        temp = temp->next;
    }
}

void BFS(int start) {
    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);
        struct Node* temp = adjList[currentVertex];

        while (temp) {
            int connectedVertex = temp->vertex;
            if (!visited[connectedVertex]) {
                visited[connectedVertex] = 1;
                queue[++rear] = connectedVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices, edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency list and visited array
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    displayList(vertices);

    printf("\nDFS Traversal starting from vertex 0: ");
    DFS(0);

    // Reset visited array for BFS
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("\nBFS Traversal starting from vertex 0: ");
    BFS(0);

    return 0;
}
