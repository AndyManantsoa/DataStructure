// Implement Graphs and represent and and adjacency matrix 
// Implement basic operations with traversals (BFS and DFS)

// Create a graph for adjacency matrix

#inlude<stdio.h>
#inc
struct GraphAdjMatrix * createGraphAdjMatrix(int vertices) {
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
