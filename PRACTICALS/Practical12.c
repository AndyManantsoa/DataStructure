
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure using adjacency list
struct GraphAdjList {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Graph structure using adjacency matrix
struct GraphAdjMatrix {
    int numVertices;
    int adjMatrix[MAX][MAX];
    int visited[MAX];
};

// Function to create a node for adjacency list
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph for adjacency list
struct GraphAdjList* createGraphAdjList(int vertices) {
    struct GraphAdjList* graph = malloc(sizeof(struct GraphAdjList));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add edge to adjacency list
void addEdgeAdjList(struct GraphAdjList* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS traversal for adjacency list
void DFSAdjList(struct GraphAdjList* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFSAdjList(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// BFS traversal for adjacency list
void BFSAdjList(struct GraphAdjList* graph, int startVertex) {
    struct Node* adjList;
    struct Node* temp;

    int* queue = malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front != rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        adjList = graph->adjLists[currentVertex];
        temp = adjList;

        while (temp != NULL) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    free(queue);
}

// Create a graph for adjacency matrix
struct GraphAdjMatrix* createGraphAdjMatrix(int vertices) {
    struct GraphAdjMatrix* graph = malloc(sizeof(struct GraphAdjMatrix));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
        graph->visited[i] = 0;
    }

    return graph;
}

// Add edge to adjacency matrix
void addEdgeAdjMatrix(struct GraphAdjMatrix* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// DFS traversal for adjacency matrix
void DFSAdjMatrix(struct GraphAdjMatrix* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && graph->visited[i] == 0) {
            DFSAdjMatrix(graph, i);
        }
    }
}

// BFS traversal for adjacency matrix
void BFSAdjMatrix(struct GraphAdjMatrix* graph, int startVertex) {
    int queue[MAX];
    int front = 0, rear = 0;

    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front != rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && graph->visited[i] == 0) {
                graph->visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// Main function to demonstrate both implementations
int main() {
    int vertices = 4;

    // Adjacency List Implementation
    struct GraphAdjList* adjListGraph = createGraphAdjList(vertices);
    addEdgeAdjList(adjListGraph, 0, 1);
    addEdgeAdjList(adjListGraph, 1, 4);
    addEdgeAdjList(adjListGraph, 0, 2);
    addEdgeAdjList(adjListGraph, 1, 3);
    
    printf("DFS for Adjacency List:\n");
    DFSAdjList(adjListGraph, 0);

    printf("\nBFS for Adjacency List:\n");
    for (int i = 0; i < vertices; i++) adjListGraph->visited[i] = 0;  // Reset visited array
    BFSAdjList(adjListGraph, 0);

    printf("\n\n");

    // Adjacency Matrix Implementation
    struct GraphAdjMatrix* adjMatrixGraph = createGraphAdjMatrix(vertices);
    addEdgeAdjMatrix(adjMatrixGraph, 0, 1);
    addEdgeAdjMatrix(adjMatrixGraph, 0, 4);
    addEdgeAdjMatrix(adjMatrixGraph, 1, 2);
    addEdgeAdjMatrix(adjMatrixGraph, 1, 3);
   

    printf("DFS for Adjacency Matrix:\n");
    DFSAdjMatrix(adjMatrixGraph, 0);

    printf("\nBFS for Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) adjMatrixGraph->visited[i] = 0;  // Reset visited array
    BFSAdjMatrix(adjMatrixGraph, 0);

    return 0;
}
