//12. Implement Graphs and represent using adjaceny list and 
//    Implement basic operations with traversals (BFS and DFS) 

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//node for adjacent list

struct Node{
    int vertex;
    struct Node * next;
};

//Graph structure using adjency list

struct graphAdjList{
    int numberOfVertices;
    struct Node ** adjLists;
    int * visited;
};

// Graph structure using adjacency matrix
struct graphAdjMatrix {
    int numberOfVertices;
    int adjMatrix[MAX][MAX];
    int visited[MAX];
};


// Function to create a node for adjacency list
struct Node* createNode(int newVertex) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = newVertex;
    newNode->next = NULL;
    return newNode;
};

struct graphAdjList* createGraphAdjList(int vertices) {
    struct graphAdjList* graph = malloc(sizeof(struct graphAdjList));
    graph->numberOfVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
};


// Add edge to adjacency list and add the value of each verteces 
void addEdgeAdjList(struct graphAdjList* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
};

// DFS traversal for adjacency list
void DFSAdjList(struct graphAdjList* graph, int vertex) {
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
};

// BFS traversal for adjacency list
void BFSAdjList(struct graphAdjList* graph, int startVertex) {
    struct Node* adjList;
    struct Node* temp;

    int* queue = malloc(graph->numberOfVertices * sizeof(int));
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

// Main function to demonstrate both implementations
int main() {
    int vertices = 5;

    // Adjacency List Implementation
    struct graphAdjList* adjListGraph = createGraphAdjList(vertices);
    addEdgeAdjList(adjListGraph, 0, 1);
    addEdgeAdjList(adjListGraph, 0, 4);
    addEdgeAdjList(adjListGraph, 1, 2);
    addEdgeAdjList(adjListGraph, 1, 3);
    addEdgeAdjList(adjListGraph, 1, 4);
    addEdgeAdjList(adjListGraph, 2, 3);
    addEdgeAdjList(adjListGraph, 3, 4);

    printf("DFS for Adjacency List:\n");
    DFSAdjList(adjListGraph, 0);

    printf("\nBFS for Adjacency List:\n");
    for (int i = 0; i < vertices; i++) adjListGraph->visited[i] = 0;  // Reset visited array
    BFSAdjList(adjListGraph, 0);

    printf("\n\n");

    return 0;
}
