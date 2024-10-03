//12. Implement Graphs and represent using adjaceny list and adjacency matrix and 
//    Implement basic operations with traversals (BFS and DFS) 

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//node for adjacent list

typedef struct Node{
    int vertex;
    Node * next;
}Node;

//Graph structure using adjency list

struct graphAdjList{
    int numberOfVertices;
    Node ** adjLists;
    int * visited;
}

// Graph structure using adjacency matrix
struct GraphAdjMatrix {
    int numberOfVertices;
    int adjMatrix[MAX][MAX];
    int visited[MAX];
};

// Function to create a node for adjacency list
Node* createNode(int newVertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = newVertex;
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
