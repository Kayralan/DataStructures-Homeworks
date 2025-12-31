#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int adjMatrix[MAX][MAX];
    int numVertices;
} Graph;

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

bool isQueueEmpty() {
    return front == -1 || front > rear;
}

void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

void DFS(Graph* g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

void BFS(Graph* g, int startVertex) {
    bool visited[MAX] = {false};

    visited[startVertex] = true;
    enqueue(startVertex);

    while (!isQueueEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(i);
            }
        }
    }
}

int main() {
    Graph g;
    initGraph(&g, 5);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4);

    printf("DFS: ");
    bool visited[MAX] = {false};
    DFS(&g, 0, visited);

    printf("\nBFS: ");
    front = -1; rear = -1;
    BFS(&g, 0);

    printf("\n");
    return 0;
}
